#include "warshall.h"

#include <Input.hpp>

#include <algorithm>

#include <Label.hpp>
#include <OS.hpp>
#include <Viewport.hpp>

using namespace godot;

void Warshall::_register_methods()
{
    register_method("_ready", &Warshall::_ready);
    register_method("_process", &Warshall::_process);
    register_method("toggle_fullscreen", &Warshall::toggle_fullscreen);
    register_method("reset", &Warshall::reset);
    register_method("next_slide", &Warshall::next_slide);
    register_method("next_k", &Warshall::next_k);
    register_method("next_path", &Warshall::next_path);
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
    m_toggle_fullscreen_button = get_node<Button>("Sidebar/SlideControl/ToggleFullscreen");
    m_reset_button             = get_node<Button>("Sidebar/ResetControl/ResetButton");
    m_node_num_input           = get_node<SpinBox>("Sidebar/ResetControl/NodeNumInput");

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

    // update graph camera
    auto [rect_center, rect_size] = m_graph->get_pleasant_bounding_rect();
    Vector2 graph_vp_size         = m_graph_viewport_container->get_size();
    float   zoom                  = std::max(rect_size.x / graph_vp_size.x, rect_size.y / graph_vp_size.y);
    m_camera->set_zoom(Vector2(zoom, zoom));
    m_camera->set_position(rect_center);

    // handle inputs
    if(input->is_action_just_pressed("quit"))
        quick_exit(0);

    m_graph->reset_styles();
    reset_matrix_styles();
    color_hovered();
    // color m_k if valid
    if(m_k != -1 && m_k < m_graph->get_adj().size())
        color_node(m_k, Color(0.0, 0.0, 1.0));
}

void Warshall::toggle_fullscreen()
{
    OS* os = OS::get_singleton();
    os->set_window_fullscreen(!os->is_window_fullscreen());
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
    m_text->set_bbcode(slide_0_text);

    const matrix& dist_mat = m_graph->get_dist_mat();
    int           n        = dist_mat.size();

    // reset all labels
    for(int i {0}; i < m_matrix_size; ++i)
        for(int j {0}; j < m_matrix_size; ++j)
            m_label_matrix[i][j]->set_text("");

    m_dist_matrix = matrix(n, std::vector<int>(n, iinf));
    for(int i {0}; i < n; ++i) {
        for(int j {0}; j < n; ++j) {
            if(dist_mat[i][j] == 1)
                set_label_mat_val(i, j, 1);
            else
                set_label_mat_val(i, j, 0);
        }
    }
}
void Warshall::slide_1()
{
    // initial distance matrix
    m_text->set_bbcode(slide_1_text);

    const matrix& dist_mat = m_graph->get_dist_mat();
    int           n        = dist_mat.size();

    m_dist_matrix = matrix(n, std::vector<int>(n, iinf));
    m_path_matrix = matrix(n, std::vector<int>(n, -1));
    for(int i {0}; i < n; ++i) {
        for(int j {0}; j < n; ++j) {
            if(i == j) {
                set_label_mat_val(i, j, 0);
                m_dist_matrix[i][j] = 0;
                m_path_matrix[i][j] = j;
            }
            else if(dist_mat[i][j] == 1) {
                set_label_mat_val(i, j, 1);
                m_dist_matrix[i][j] = 1;
                m_path_matrix[i][j] = j;
            }
            else {
                set_mat_inf(i, j);
                m_dist_matrix[i][j] = iinf;
                m_path_matrix[i][j] = -1;
            }
        }
    }
}
void Warshall::slide_2()
{
    // updating distance matrix
    m_next_slide_button->set_disabled(true);
    m_next_path_button->set_disabled(false);
    m_next_k_button->set_disabled(false);
    m_text->set_bbcode(slide_2_text);

    m_k = 0;
    m_i = 0;
    m_j = 0;
}
void Warshall::slide_3()
{
    // conclusion
    m_next_slide_button->set_disabled(true);
    m_next_path_button->set_disabled(true);
    m_next_k_button->set_disabled(true);
    m_text->set_bbcode(slide_3_text);

    m_k = -1;
    m_i = -1;
    m_j = -1;
}

void Warshall::create_matrix()
{
    // columns
    m_matrix_cols = std::vector<Label*>(m_matrix_size, nullptr);
    for(int i {0}; i < m_matrix_size; ++i) {
        m_matrix_cols[i] = Label::_new();
        m_matrix_cols[i]->set_position(Vector2(m_cell_size.x * (i + 1), 0));
        m_matrix_cols[i]->set_text(std::to_string(i).c_str());
        m_matrix_parent->add_child(m_matrix_cols[i]);
    }
    // rows
    m_matrix_rows = std::vector<Label*>(m_matrix_size, nullptr);
    for(int j {0}; j < m_matrix_size; ++j) {
        m_matrix_rows[j] = Label::_new();
        m_matrix_rows[j]->set_position(Vector2(0, m_cell_size.y * (j + 1)));
        m_matrix_rows[j]->set_text(std::to_string(j).c_str());
        m_matrix_parent->add_child(m_matrix_rows[j]);
    }
    // actual matrix
    m_label_matrix = matrix_temp<Label*>(m_matrix_size, std::vector<Label*>(m_matrix_size, nullptr));
    for(int i {0}; i < m_matrix_size; ++i) {
        for(int j {0}; j < m_matrix_size; ++j) {
            m_label_matrix[i][j] = Label::_new();
            m_label_matrix[i][j]->set_position(Vector2(m_cell_size.x * (i + 1), m_cell_size.y * (j + 1)));
            m_matrix_parent->add_child(m_label_matrix[i][j]);
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

bool Warshall::is_label_hovered(const Label* label) const
{
    Vector2 size      = label->get_size();
    Vector2 mouse_pos = label->get_local_mouse_position();
    return mouse_pos.x >= 0 && mouse_pos.x < size.x && mouse_pos.y >= 0 && mouse_pos.y < size.y;
}

void Warshall::color_hovered()
{
    int     n              = m_graph->get_adj().size();
    Vector2 mouse_pos      = m_matrix_parent->get_local_mouse_position();
    int     mouse_coords_x = mouse_pos.x / m_cell_size.x;
    int     mouse_coords_y = mouse_pos.y / m_cell_size.y;

    // hovering over node
    int i = m_graph->get_hovered_node();
    // hovering over side of matrix
    if(i == -1) {
        if(mouse_coords_x == 0 && mouse_coords_y > 0 && mouse_coords_y < n + 1)
            i = mouse_coords_y - 1;
        else if(mouse_coords_y == 0 && mouse_coords_x > 0 && mouse_coords_x < n + 1)
            i = mouse_coords_x - 1;
    }

    // color node and connected edges
    if(i != -1) {
        GraphNode* node = m_graph->get_node(i);
        color_node(i, m_hover_color);
        for(int j: m_graph->get_adj()[i]) {
            color_path(i, j, m_hover_color);
        }
    }

    // hovering over element in matrix
    if(mouse_coords_x > 0 && mouse_coords_x < n + 1 && mouse_coords_y > 0 && mouse_coords_y < n + 1)
        color_path(mouse_coords_x - 1, mouse_coords_y - 1, m_hover_color);
}

void Warshall::color_path(int i, int j, Color color)
{
    // the matrix must be a distance matrix -> not present in slide 0
    if(m_cur_slide == 0)
        return;
    // don't use the graph's path matrix, use the one by the presented algorithm
    if(m_dist_matrix[i][j] == iinf)
        return;
    std::vector<int> path = get_path(i, j);
    for(int i {1}; i < path.size(); ++i) {
        int a = path[i - 1];
        int b = path[i];
        m_graph->set_edge_color(a, b, color);
        m_graph->set_edge_color(b, a, color);
        set_mat_style(a, b, color);
        set_mat_style(b, a, color);
    }
}

void Warshall::color_node(int i, Color color)
{
    m_graph->get_node(i)->set_fill_color(color);
    set_mat_row_style(i, color);
    set_mat_col_style(i, color);
}
