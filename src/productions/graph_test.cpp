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
    m_random = RandomNumberGenerator::_new();
    m_random->randomize();
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

    get_random_graph(100);
    m_graph->set_zero_based_adjacency_list(m_adj);

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
        get_random_graph(30);
        m_graph->set_zero_based_adjacency_list(m_adj);
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
    for(int i {0}; i < adj.size(); ++i) {
        GraphNode* node = m_graph->get_node(i);
        node->set_fill_color(Color(1.0, 1.0, 1.0));
    }
    for(int i {0}; i < adj.size(); ++i)
        for(int j {0}; j < adj.size(); ++j) {
            m_graph->set_edge_color(i, j, Color(1.0, 1.0, 1.0));
        }
    for(int i {0}; i < adj.size(); ++i) {
        GraphNode* node = m_graph->get_node(i);
        if((node->get_position() - mouse_pos).length() < node->get_radius()) {
            node->set_fill_color(Color(0.2, 0.2, 0.2));

            for(int j {0}; j < adj.size(); ++j) {
                GraphNode* other_node = m_graph->get_node(j);
                if(dist_mat[i][j] == 1) {
                    other_node->set_fill_color(Color(1.0, 0.0, 0.0));
                    m_graph->set_edge_color(i, j, Color(1.0, 0.0, 0.0));
                    m_graph->set_edge_color(j, i, Color(1.0, 0.0, 0.0));
                }
                else if(dist_mat[i][j] == 2) {
                    other_node->set_fill_color(Color(0.8, 0.0, 0.8));
                    m_graph->set_edge_color(i, j, Color(0.8, 0.0, 0.8));
                    m_graph->set_edge_color(j, i, Color(0.8, 0.0, 0.8));
                }
                else if(dist_mat[i][j] == 3) {
                    other_node->set_fill_color(Color(0.1, 0.7, 0.2));
                    m_graph->set_edge_color(i, j, Color(0.1, 0.7, 0.2));
                    m_graph->set_edge_color(j, i, Color(0.1, 0.7, 0.2));
                }
            }

            return;
        }
    }
}

void GraphTest::get_input()
{
#include "graph_input.h"
    int n, m;
    input >> n >> m;

    m_adj = adjacency_list(n + 1);
    for(int i {0}; i < m; ++i) {
        int a, b;
        input >> a >> b;
        m_adj[a].insert(b);
        m_adj[b].insert(a);
    }
}

void GraphTest::get_random_graph(int n)
{
    int y_max = static_cast<int>(std::sqrt(n));
    int y_cut = m_random->randi_range(0, y_max - 1);
    m_adj     = adjacency_list(n);
    // ([0, n/y_max - 1], [0, y_max - 1])
    std::vector<Vector2> pos(n);

    int x = 0;
    int y = 0;
    for(int i {0}; i < n; ++i) {
        pos[i] = Vector2(x, y);
        ++y;
        if(y >= y_max) {
            y = 0;
            ++x;
        }
    }

    for(int a {0}; a < n; ++a) {
        for(int b {0}; b < n; ++b) {
            if(a == b)
                continue;
            // don't go over cut -> produce two cluster
            if(pos[a].y < y_cut != pos[b].y < y_cut)
                continue;
            float len = (pos[a] - pos[b]).length();
            if(len < 2 && !m_random->randi_range(0, 5)) {
                m_adj[a].insert(b);
                m_adj[b].insert(a);
            }
            if(len > 2 && len <= 4 && !m_random->randi_range(0, 15)) {
                m_adj[a].insert(b);
                m_adj[b].insert(a);
            }
            // if(len > 4 && len <= 8 && !m_random->randi_range(0, 14)) {
            //     m_adj[a].insert(b);
            //     m_adj[b].insert(a);
            // }
        }
    }

    // for(int a {0}; a < n; ++a) {
    //     int c = m_random->randi_range(0, 2);
    //     for(int s {0}; s < c; ++s) {
    //         int b = m_random->randi_range(0, n - 1);
    //         m_adj[a].insert(b);
    //     }
    // }
}
