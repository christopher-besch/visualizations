#include "graph.h"
#include "graph_node.h"

#include <set>
#include <sstream>
#include <string>
#include <vector>

#include <Object.hpp>
#include <PackedScene.hpp>
#include <ResourceLoader.hpp>

#define prt(x) Godot::print(String((std::stringstream("") << x).str().c_str()))

using namespace godot;

void Graph::_register_methods()
{
    register_method("_ready", &Graph::_ready);
}

void Graph::_init()
{
    ResourceLoader* relo = ResourceLoader::get_singleton();
    m_graph_node_scene   = relo->load("res://graph/graph_node.tscn");
}

void Graph::_ready()
{
}

void Graph::set_adjacency_list(const adjacency_list& adj, int n)
{
    for(int i {1}; i <= n; ++i) {
        GraphNode* graph_node = instance_graph_node();
        graph_node->set_position(Vector2(i * 200.0, 200.0));
        graph_node->set_text(std::to_string(i).c_str());
        add_child(graph_node);
        prt(i);
    }
}
