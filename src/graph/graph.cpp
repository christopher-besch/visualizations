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
    register_method("get_center_of_mass", &Graph::get_center_of_mass);
}

void Graph::_init()
{
    ResourceLoader* relo = ResourceLoader::get_singleton();
    m_graph_node_scene   = relo->load("res://graph/graph_node.tscn");
    m_node_radius        = 20.0;
}

void Graph::_ready()
{
    m_edges = get_node<GraphEdges>("GraphEdges");
}

void Graph::set_adjacency_list(const adjacency_list& adj)
{
    int n = adj.size();
    m_nodes.resize(n, nullptr);
    for(int i {0}; i < n; ++i) {
        GraphNode* graph_node = instance_graph_node();
        graph_node->set_text(std::to_string(i).c_str());
        graph_node->set_radius(m_node_radius);
        add_child(graph_node);
        m_nodes[i] = graph_node;
    }
    m_adj = adjacency_list(n);
    for(int i {0}; i < n; ++i)
        for(int o: adj[i])
            m_adj[i].insert(o);

    for(int i {0}; i < n; ++i) {
        for(int o {0}; o < n; ++o) {
            if(adj[i].count(o) != 0)
                m_nodes[i]->add_attractor(m_nodes[o], 150);
            else
                m_nodes[i]->add_attractor(m_nodes[o], 400);
        }
    }
    m_edges->set_nodes(&m_nodes, &m_adj);
}

void Graph::set_one_based_adjacency_list(const adjacency_list& adj)
{
    int            n = adj.size() - 1;
    adjacency_list new_adj(n);
    for(int i {1}; i <= n; ++i) {
        for(int o: adj[i]) {
            new_adj[i - 1].insert(o - 1);
        }
    }
    set_adjacency_list(new_adj);
    for(int i {0}; i < m_nodes.size(); ++i) {
        prt(i + 1);
        m_nodes[i]->set_text(std::to_string(i + 1).c_str());
    }
}

Vector2 Graph::get_center_of_mass() const
{
    Vector2 sum = Vector2(0.0, 0.0);
    for(GraphNode* node: m_nodes)
        sum += node->get_position();
    Vector2 center = sum / m_nodes.size();
    return center;
}

std::pair<Vector2, Vector2> Graph::get_bounding_rect() const
{
    Vector2 bottom_right = Vector2(-finf, -finf);
    Vector2 top_left     = Vector2(finf, finf);
    for(const GraphNode* node: m_nodes) {
        Vector2 pos  = node->get_position();
        bottom_right = Vector2(std::max(bottom_right.x, pos.x), std::max(bottom_right.y, pos.y));
        top_left     = Vector2(std::min(top_left.x, pos.x), std::min(top_left.y, pos.y));
    }
    Vector2 size   = bottom_right - top_left;
    Vector2 center = top_left + size / 2;
    // add padding for node circle radius
    Vector2 padded_size = size + 2.0 * m_node_radius * Vector2::ONE;
    return {center, padded_size};
}
