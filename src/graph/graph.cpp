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
    register_method("_process", &Graph::_process);
    register_method("_draw", &Graph::_draw);
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
}

void Graph::_process()
{
    update();
}

void Graph::_draw()
{
    for(int i {0}; i < m_nodes.size(); ++i) {
        for(int o: m_adj[i]) {
            EdgeStyle& style = m_edge_styles[i][o];
            draw_line(m_nodes[i]->get_position(), m_nodes[o]->get_position(), style.color, style.width, true);
        }
    }
}

void Graph::free_nodes_edges()
{
    for(int i {0}; i < m_nodes.size(); ++i) {
        m_nodes[i]->queue_free();
    }
    m_nodes.clear();
    m_edge_styles.clear();
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
    free_nodes_edges();
    m_nodes.resize(n, nullptr);
    m_edge_styles.resize(n, std::vector<EdgeStyle>(n));
    for(int i {0}; i < n; ++i) {
        m_nodes[i] = instance_graph_node();
        m_nodes[i]->set_radius(m_node_radius);
        add_child(m_nodes[i]);
    }

    for(int i {0}; i < n; ++i)
        m_nodes[i]->set_all_nodes(&m_nodes, i);

    calc_paths();
    calc_order();
    position_nodes();

    apply_attractions();
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
