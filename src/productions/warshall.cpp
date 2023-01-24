#include "warshall.h"

#include <Input.hpp>

#include <algorithm>

#include <Label.hpp>
#include <Viewport.hpp>

using namespace godot;

void Warshall::_register_methods()
{
    register_method("_ready", &Warshall::_ready);
    register_method("_process", &Warshall::_process);
    register_method("reset", &Warshall::reset);
    register_method("next_slide", &Warshall::next_slide);
}

void Warshall::_init()
{
}

void Warshall::_ready()
{
    m_graph_viewport_container = get_node<ViewportContainer>("GraphViewportContainer");
    m_graph                    = get_node<Graph>("GraphViewportContainer/GraphViewport/Graph");
    m_camera                   = get_node<Camera2D>("GraphViewportContainer/GraphViewport/Camera");
    m_sidebar                  = get_node<Position2D>("Sidebar");
    m_sidebar_background       = get_node<MeshInstance2D>("Sidebar/SidebarBackground");
    m_matrix_parent            = get_node<Position2D>("Sidebar/MatrixParent");
    m_text                     = get_node<RichTextLabel>("Sidebar/Text");
    m_next_path_button         = get_node<Button>("Sidebar/SlideControl/NextPath");
    m_next_k_button            = get_node<Button>("Sidebar/SlideControl/NextK");
    m_next_slide_button        = get_node<Button>("Sidebar/SlideControl/NextSlide");
    m_reset_button             = get_node<Button>("Sidebar/ResetControl/ResetButton");
    m_node_num_input           = get_node<SpinBox>("Sidebar/ResetControl/NodeNumInput");

    // use position of sidebar to determine its size
    Vector2 root_vp_size = get_viewport()->get_size();
    m_sidebar_width      = root_vp_size.x - m_sidebar->get_position().x;

    create_matrix();

    reset();
}

void Warshall::_process(float delta)
{
    Input* input = Input::get_singleton();

    // resize viewport
    Vector2 root_vp_size       = get_viewport()->get_size();
    float   new_graph_vp_width = root_vp_size.x - m_sidebar_width;
    m_graph_viewport_container->set_size(Vector2(new_graph_vp_width, root_vp_size.y));
    // resize sidebar
    m_sidebar->set_position(Vector2(new_graph_vp_width, 0));
    // resize sidebar background
    Transform2D sidebar_background_trans = m_sidebar_background->get_transform();
    sidebar_background_trans.set_rotation_and_scale(0, Vector2(m_sidebar_width, root_vp_size.y));
    m_sidebar_background->set_transform(sidebar_background_trans);

    // update camera
    auto [rect_center, rect_size] = m_graph->get_pleasant_bounding_rect();
    Vector2 graph_vp_size         = m_graph_viewport_container->get_size();
    float   zoom                  = std::max(rect_size.x / graph_vp_size.x, rect_size.y / graph_vp_size.y);
    m_camera->set_zoom(Vector2(zoom, zoom));
    m_camera->set_position(rect_center);

    // handle inputs
    if(input->is_action_just_pressed("quit"))
        quick_exit(0);

    // handle mouse hovering
    m_graph->reset_styles();
    reset_matrix_styles();
    // set node and edges color
    int i = m_graph->get_hovered_node();
    if(i != -1) {
        GraphNode* node = m_graph->get_node(i);
        node->set_fill_color(m_hover_color);
        set_mat_row_style(i, m_hover_color);
        set_mat_col_style(i, m_hover_color);
        for(int j: m_graph->get_adj()[i]) {
            m_graph->set_edge_color(i, j, m_hover_color);
            m_graph->set_edge_color(j, i, m_hover_color);
            set_mat_style(i, j, m_hover_color);
            set_mat_style(j, i, m_hover_color);
        }
    }
}

void Warshall::reset()
{
    int n = m_node_num_input->get_value();
    m_graph->set_con_attr(std::max(150, 10 * n));
    m_graph->set_uncon_attr(std::max(300, 20 * n));
    m_graph->set_random_adj(n);
    m_graph->set_default_labels();
    m_cur_slide = -1;

    next_slide();
}

void Warshall::next_slide()
{
    ++m_cur_slide;
    switch(m_cur_slide) {
    case 0:
        slide_0();
        break;
    case 1:
        slide_1();
        break;
    case 2:
        slide_2();
        break;
    case 3:
        slide_3();
        break;
    case 4:
        slide_4();
        break;
    case 5:
        slide_5();
        break;
    default:
        throw "invalid slide id";
    }
}

void Warshall::slide_0()
{
    // adjacency matrix
    m_next_slide_button->set_disabled(false);
    m_next_path_button->set_disabled(true);
    m_next_k_button->set_disabled(true);
    m_text->set_bbcode(get_slide_text(0));

    const matrix& dist_mat = m_graph->get_dist_mat();
    int           n        = dist_mat.size();

    reset_matrix();
    for(int i {0}; i < n; ++i) {
        for(int j {0}; j < n; ++j) {
            if(dist_mat[i][j] == 1)
                set_mat_val(i, j, 1);
            else
                set_mat_val(i, j, 0);
        }
    }
}
void Warshall::slide_1()
{
    // distance matrix
    m_text->set_bbcode(get_slide_text(1));
}
void Warshall::slide_2()
{
    // updating distance matrix
    m_text->set_bbcode(get_slide_text(2));
}
void Warshall::slide_3()
{
    // path traversal
    m_text->set_bbcode(get_slide_text(3));
}
void Warshall::slide_4()
{
    // updating next node matrix
    m_text->set_bbcode(get_slide_text(4));
}
void Warshall::slide_5()
{
    // conclusion
    m_text->set_bbcode(get_slide_text(5));
    m_next_slide_button->set_disabled(true);
}

void Warshall::create_matrix()
{
    // columns
    m_matrix_cols = std::vector<Label*>(m_matrix_size, nullptr);
    for(int i {0}; i < m_matrix_size; ++i) {
        m_matrix_cols[i] = Label::_new();
        m_matrix_cols[i]->set_position(Vector2(25 * (i + 1), 0));
        m_matrix_cols[i]->set_text(std::to_string(i).c_str());
        m_matrix_parent->add_child(m_matrix_cols[i]);
    }
    // rows
    m_matrix_rows = std::vector<Label*>(m_matrix_size, nullptr);
    for(int j {0}; j < m_matrix_size; ++j) {
        m_matrix_rows[j] = Label::_new();
        m_matrix_rows[j]->set_position(Vector2(0, 20 * (j + 1)));
        m_matrix_rows[j]->set_text(std::to_string(j).c_str());
        m_matrix_parent->add_child(m_matrix_rows[j]);
    }
    m_matrix = matrix_temp<Label*>(m_matrix_size, std::vector<Label*>(m_matrix_size, nullptr));
    for(int i {0}; i < m_matrix_size; ++i) {
        for(int j {0}; j < m_matrix_size; ++j) {
            m_matrix[i][j] = Label::_new();
            m_matrix[i][j]->set_position(Vector2(25 * (i + 1), 20 * (j + 1)));
            m_matrix[i][j]->set_text("13");
            m_matrix_parent->add_child(m_matrix[i][j]);
        }
    }
}

void Warshall::reset_matrix()
{
    for(int i {0}; i < m_matrix_size; ++i) {
        for(int j {0}; j < m_matrix_size; ++j) {
            m_matrix[i][j]->set_text("");
        }
    }
}

void Warshall::reset_matrix_styles()
{
    for(int i {0}; i < m_matrix_size; ++i) {
        set_mat_row_style(i, Color(1.0, 1.0, 1.0));
        set_mat_col_style(i, Color(1.0, 1.0, 1.0));
        for(int j {0}; j < m_matrix_size; ++j)
            set_mat_style(i, j, Color(1.0, 1.0, 1.0));
    }
}
