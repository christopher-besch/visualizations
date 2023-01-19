#include "graph_test.h"

#include <Input.hpp>

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
#include "graph_input.h"

    int n, m;
    input >> n >> m;

    std::vector<std::set<int>> adj(n + 1);
    for(int i {0}; i <= m; ++i) {
        int a, b;
        input >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    std::stringstream out;
    for(int i {1}; i <= n; ++i) {
        out << i << ": ";
        for(int e: adj[i]) {
            out << e << ", ";
        }
        out << std::endl;
    }
    prt(out.str());

    m_graph = get_node<Graph>("Graph");
    m_graph->set_one_based_adjacency_list(adj, n);

    m_camera = get_node<Camera2DCtrl>("Camera");
}

void GraphTest::_process(float delta)
{
    Input* input = Input::get_singleton();

    if(input->is_action_just_pressed("recenter")) {
        Vector2 sum = Vector2(0.0, 0.0);
        for(GraphNode* node: *(m_graph->get_nodes()))
            sum += node->get_position();
        Vector2 avg = sum / m_graph->get_nodes()->size();
        m_camera->set_position(avg);
    }
}
