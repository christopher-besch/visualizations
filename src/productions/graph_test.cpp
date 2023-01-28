#include "graph_test.h"

#include <Input.hpp>

#include <cmath>
#include <sstream>

using namespace godot;

void GraphTest::_register_methods()
{
    register_method("_ready", &GraphTest::_ready);
    register_method("_process", &GraphTest::_process);
}

void GraphTest::_init()
{
}

void GraphTest::_ready()
{
    m_graph = get_node<Graph>("Graph");
    m_graph->set_con_attr(250);
    m_graph->set_uncon_attr(400);
    // m_graph->set_con_attr(500);
    // m_graph->set_uncon_attr(1000);

    // get_input();
    // m_graph->set_one_based_adjacency_list(m_adj);

    m_graph->set_random_adj(60);
    m_graph->set_default_labels();

    m_camera = get_node<Camera2DCtrl>("Camera");
}

void GraphTest::_process(float delta)
{
    Input* input = Input::get_singleton();

    if(input->is_action_just_pressed("recenter")) {
        m_camera->zoom_to_rect(m_graph->get_pleasant_bounding_rect());
    }
    if(input->is_action_just_pressed("reset_physics")) {
        m_graph->position_nodes();
    }
    if(input->is_action_just_pressed("reset")) {
        m_graph->set_random_adj(30);
        m_graph->set_default_labels();
    }
    if(input->is_action_just_pressed("increase_con_attr")) {
        prt("con: " << m_graph->get_con_attr() << " uncon: " << m_graph->get_uncon_attr());
        m_graph->set_con_attr(m_graph->get_con_attr() + 20);
    }
    if(input->is_action_just_pressed("increase_uncon_attr")) {
        prt("con: " << m_graph->get_con_attr() << " uncon: " << m_graph->get_uncon_attr());
        m_graph->set_uncon_attr(m_graph->get_uncon_attr() + 20);
    }
    if(input->is_action_just_pressed("decrease_con_attr")) {
        prt("con: " << m_graph->get_con_attr() << " uncon: " << m_graph->get_uncon_attr());
        m_graph->set_con_attr(m_graph->get_con_attr() - 20);
    }
    if(input->is_action_just_pressed("decrease_uncon_attr")) {
        prt("con: " << m_graph->get_con_attr() << " uncon: " << m_graph->get_uncon_attr());
        m_graph->set_uncon_attr(m_graph->get_uncon_attr() - 20);
    }
    if(input->is_action_just_pressed("quit"))
        quick_exit(0);

    const adjacency_list& adj       = m_graph->get_adj();
    const matrix&         dist_mat  = m_graph->get_dist_mat();
    Vector2               mouse_pos = get_local_mouse_position();
    m_graph->reset_styles();
    // set color
    int i = m_graph->get_hovered_node();
    if(i != -1) {
        GraphNode* node = m_graph->get_node(i);
        // is hovered
        node->set_fill_color(Color(0.2, 0.2, 0.2));

        // if(dist_mat[i][24] != iinf)
        //     color_path(i, 24, Color(1.0, 0.2, 0.0));
        // return;
        for(int j {0}; j < adj.size(); ++j) {
            GraphNode* other_node = m_graph->get_node(j);
            if(dist_mat[i][j] == 1) {
                other_node->set_fill_color(Color(1.0, 0.0, 0.0));
                color_path(i, j, Color(1.0, 0.0, 0.0));
            }
            else if(dist_mat[i][j] == 2) {
                other_node->set_fill_color(Color(0.8, 0.0, 0.8));
                color_path(i, j, Color(0.8, 0.0, 0.8), 1);
            }
            else if(dist_mat[i][j] == 3) {
                other_node->set_fill_color(Color(0.0, 0.6, 0.2));
                color_path(i, j, Color(0.0, 0.6, 0.2), 2);
            }
        }
    }
}

void GraphTest::color_path(int start, int target, Color color, int start_draw)
{
    std::vector<int> path = m_graph->get_path(start, target);
    for(int i {start_draw + 1}; i < path.size(); ++i) {
        m_graph->set_edge_color(path[i - 1], path[i], color);
        m_graph->set_edge_color(path[i], path[i - 1], color);
    }
}

adjacency_list GraphTest::get_input()
{
#include "graph_input.h"
    int n, m;
    input >> n >> m;

    adjacency_list adj = adjacency_list(n + 1);
    for(int i {0}; i < m; ++i) {
        int a, b;
        input >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    return adj;
}
