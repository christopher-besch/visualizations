#include "graph.h"

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
    m_edges = get_node<GraphEdges>("GraphEdges");
}

void Graph::set_adjacency_list(const adjacency_list& adj, int n)
{
    m_nodes.resize(n, nullptr);
    for(int i {0}; i < n; ++i) {
        GraphNode* graph_node = instance_graph_node();
        graph_node->set_text(std::to_string(i).c_str());
        add_child(graph_node);
        m_nodes[i] = graph_node;
    }
    for(int i {0}; i < n; ++i) {
        for(int o {0}; o < n; ++o) {
            if(adj[i].count(o) != 0)
                m_nodes[i]->add_attractor(m_nodes[o], 150);
            else
                m_nodes[i]->add_attractor(m_nodes[o], 300);
        }
    }
    m_edges->set_nodes(&m_nodes);
}

void Graph::set_one_based_adjacency_list(const adjacency_list& adj, int n)
{
    adjacency_list new_adj(n);
    for(int i {1}; i <= n; ++i) {
        for(int o: adj[i]) {
            new_adj[i - 1].insert(o - 1);
        }
    }
    set_adjacency_list(new_adj, n);
    for(int i {0}; i < m_nodes.size(); ++i) {
        prt(i + 1);
        m_nodes[i]->set_text(std::to_string(i + 1).c_str());
    }
}
