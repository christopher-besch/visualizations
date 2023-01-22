#include "graph.h"

#include <set>
#include <sstream>
#include <string>
#include <vector>

#include <Object.hpp>
#include <PackedScene.hpp>
#include <ResourceLoader.hpp>

using namespace godot;

void Graph::_register_methods()
{
    register_method("_ready", &Graph::_ready);
}

void Graph::_init()
{
    ResourceLoader* relo = ResourceLoader::get_singleton();
    m_graph_node_scene   = relo->load("res://graph/graph_node.tscn");
    m_node_radius        = 20.0;
    m_con_attr           = 150.0;
    m_uncon_attr         = 300.0;
}

void Graph::_ready()
{
    m_edges = get_node<GraphEdges>("GraphEdges");
}

void Graph::free_nodes()
{
    for(int i {0}; i < m_nodes.size(); ++i) {
        m_nodes[i]->queue_free();
    }
    m_nodes.clear();
}

void Graph::apply_attractions()
{
    // tell nodes who the other nodes are and how to attract
    for(int i {0}; i < m_nodes.size(); ++i) {
        for(int o {0}; o < m_nodes.size(); ++o) {
            m_nodes[i]->set_attraction(o, calc_attr(m_dist_mat[i][o]));
        }
    }
}

void Graph::reset()
{
    int n = m_adj.size();
    // generate nodes
    free_nodes();
    m_nodes.resize(n, nullptr);
    for(int i {0}; i < n; ++i) {
        m_nodes[i] = instance_graph_node();
        m_nodes[i]->set_radius(m_node_radius);
        add_child(m_nodes[i]);
    }

    for(int i {0}; i < n; ++i)
        m_nodes[i]->set_all_nodes(&m_nodes, i);

    calc_dist_mat();
    calc_order();
    position_nodes();

    apply_attractions();
    m_edges->set_nodes(&m_nodes, &m_adj);
}

void Graph::set_zero_based_adjacency_list(const adjacency_list& adj)
{
    int n = adj.size();
    m_adj = adjacency_list(n);
    for(int i {0}; i < n; ++i)
        for(int o: adj[i])
            m_adj[i].insert(o);
    reset();
}

void Graph::set_one_based_adjacency_list(const adjacency_list& adj)
{
    int n = adj.size() - 1;
    m_adj = adjacency_list(n);
    for(int i {1}; i <= n; ++i) {
        for(int o: adj[i]) {
            m_adj[i - 1].insert(o - 1);
        }
    }
    reset();
}
