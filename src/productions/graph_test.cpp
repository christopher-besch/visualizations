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

    m_graph->set_random_adj(30);
    // set labels
    for(int i {0}; i < m_graph->get_adj().size(); ++i) {
        m_graph->get_node(i)->set_text(std::to_string(i).c_str());
    }

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
        // set labels
        for(int i {0}; i < m_graph->get_adj().size(); ++i) {
            m_graph->get_node(i)->set_text(std::to_string(i).c_str());
        }
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

    auto    adj       = m_graph->get_adj();
    auto    dist_mat  = m_graph->get_dist_mat();
    Vector2 mouse_pos = get_local_mouse_position();
    // reset
    for(int i {0}; i < adj.size(); ++i) {
        GraphNode* node = m_graph->get_node(i);
        node->set_fill_color(Color(1.0, 1.0, 1.0));
    }
    for(int i {0}; i < adj.size(); ++i)
        for(int j {0}; j < adj.size(); ++j) {
            m_graph->set_edge_color(i, j, Color(1.0, 1.0, 1.0));
        }
    // set color
    for(int i {0}; i < adj.size(); ++i) {
        GraphNode* node = m_graph->get_node(i);
        if((node->get_position() - mouse_pos).length() < node->get_radius()) {
            // is hovered
            node->set_fill_color(Color(0.2, 0.2, 0.2));

            if(dist_mat[i][24] != iinf)
                color_edges(i, 24, Color(1.0, 0.2, 0.0));
            return;
            for(int j {0}; j < adj.size(); ++j) {
                GraphNode* other_node = m_graph->get_node(j);
                if(dist_mat[i][j] == 1) {
                    other_node->set_fill_color(Color(1.0, 0.0, 0.0));
                    color_edges(i, j, Color(1.0, 0.0, 0.0));
                }
                else if(dist_mat[i][j] == 2) {
                    other_node->set_fill_color(Color(0.8, 0.0, 0.8));
                    color_edges(i, j, Color(0.8, 0.0, 0.8), 1);
                }
                else if(dist_mat[i][j] == 3) {
                    other_node->set_fill_color(Color(0.0, 0.6, 0.2));
                    color_edges(i, j, Color(0.0, 0.6, 0.2), 2);
                }
            }
            return;
        }
    }
}

void GraphTest::color_edges(int start, int target, Color color, int start_draw)
{
    auto path_mat = m_graph->get_path_mat();
    int  last;
    int  idx {0};
    while(start != target) {
        last  = start;
        start = path_mat[start][target];
        if(idx++ >= start_draw) {
            m_graph->set_edge_color(last, start, color);
            m_graph->set_edge_color(start, last, color);
        }
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
