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

    // get_input();
    // m_graph->set_one_based_adjacency_list(m_adj);

    get_random_graph(30);
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
        m_graph->reset_physics();
    }
    if(input->is_action_just_pressed("reset")) {
        get_random_graph(50);
        m_graph->set_zero_based_adjacency_list(m_adj);
    }
    if(input->is_action_just_pressed("increase_con_attr")) {
        m_graph->set_con_attr(m_graph->get_con_attr() + 20);
    }
    if(input->is_action_just_pressed("increase_uncon_attr")) {
        m_graph->set_uncon_attr(m_graph->get_uncon_attr() + 20);
    }
    if(input->is_action_just_pressed("decrease_con_attr")) {
        m_graph->set_con_attr(m_graph->get_con_attr() - 20);
    }
    if(input->is_action_just_pressed("decrease_uncon_attr")) {
        m_graph->set_uncon_attr(m_graph->get_uncon_attr() - 20);
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
    m_adj = adjacency_list(n);

    int a = static_cast<int>(std::sqrt(n));

    std::vector<Vector2> pos(n);

    int x = 0;
    int y = 0;
    for(int i {0}; i < n; ++i) {
        pos[i] = Vector2(x, y);
        ++y;
        if(y > a) {
            y = 0;
            ++x;
        }
    }

    for(int a {0}; a < n; ++a) {
        for(int b {0}; b < n; ++b) {
            if(a == b)
                continue;
            float len = (pos[a] - pos[b]).length();
            if(len < 2 && !m_random->randi_range(0, 5)) {
                m_adj[a].insert(b);
                m_adj[b].insert(a);
            }
            // if(len > 2 && len <= 4 && !m_random->randi_range(0, 7)) {
            //     m_adj[a].insert(b);
            //     m_adj[b].insert(a);
            // }
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
