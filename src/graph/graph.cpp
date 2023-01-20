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
    register_method("get_center_of_mass", &Graph::get_center_of_mass);
    register_method("recalculate_pos", &Graph::reset_physics);
    register_method("reset", &Graph::reset);
    register_property<Graph, float>("con_attr", &Graph::set_con_attr, &Graph::get_con_attr, 150.0);
    register_property<Graph, float>("uncon_attr", &Graph::set_uncon_attr, &Graph::get_uncon_attr, 300.0);
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

void Graph::reset_physics()
{
    Vector2 center = get_center_of_mass();
    for(GraphNode* node: m_nodes)
        node->set_target_pos(center);
}

void Graph::reset()
{
    int n = m_adj.size();
    // generate nodes
    free_nodes();
    m_nodes.resize(n, nullptr);
    for(int i {0}; i < n; ++i) {
        m_nodes[i] = instance_graph_node();
        m_nodes[i]->set_text(std::to_string(i).c_str());
        m_nodes[i]->set_radius(m_node_radius);
        add_child(m_nodes[i]);
    }

    for(int i {0}; i < n; ++i)
        m_nodes[i]->set_all_nodes(&m_nodes, i);

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
    calc_dist_mat();
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
    calc_dist_mat();
    reset();
    for(int i {0}; i < m_nodes.size(); ++i) {
        prt(i + 1);
        m_nodes[i]->set_text(std::to_string(i + 1).c_str());
    }
}

void Graph::calc_dist_mat()
{
    int n      = m_adj.size();
    m_dist_mat = distance_matrix(n, std::vector<int>(n, 0));
    for(int i {0}; i < n; ++i) {
        for(int j {0}; j < n; ++j) {
            if(i == j)
                m_dist_mat[i][j] = 0;
            else if(m_adj[i].count(j) != 0)
                m_dist_mat[i][j] = 1;
            else
                m_dist_mat[i][j] = iinf;
        }
    }

    for(int k {0}; k < n; ++k) {
        for(int i {0}; i < n; ++i) {
            for(int j {0}; j < n; ++j) {
                m_dist_mat[i][j] = std::min(m_dist_mat[i][j], m_dist_mat[i][k] + m_dist_mat[k][j]);
            }
        }
    }

    // // debug
    // std::stringstream out;
    // for(int i {0}; i < n; ++i) {
    //     out << i << ": ";
    //     for(int e: m_adj[i]) {
    //         out << e << ", ";
    //     }
    //     out << std::endl;
    // }
    // prt(out.str());

    // out = std::stringstream();
    // out << "  \t";
    // for(int j {0}; j < n; ++j) {
    //     out << j << "\t";
    // }
    // out << std::endl;
    // for(int i {0}; i < n; ++i) {
    //     out << i << " :\t";
    //     for(int j {0}; j < n; ++j) {
    //         int val = m_dist_mat[i][j];
    //         val     = val == iinf ? -2 : val;
    //         out << val << "\t";
    //     }
    //     out << std::endl;
    // }
    // prt(out.str());
    // // debug
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

void Graph::apply_attractions()
{
    prt("con: " << m_con_attr << " uncon: " << m_uncon_attr);
    // tell nodes who the other nodes are and how to attract
    for(int i {0}; i < m_nodes.size(); ++i) {
        for(int o {0}; o < m_nodes.size(); ++o) {
            m_nodes[i]->set_attraction(o, calc_attr(m_dist_mat[i][o]));
        }
    }
}

void Graph::free_nodes()
{
    for(int i {0}; i < m_nodes.size(); ++i) {
        m_nodes[i]->queue_free();
    }
    m_nodes.clear();
}

float Graph::calc_attr(int dist) const
{
    if(dist == 0)
        return 0.0;

    // -> 0.0 (unconnected)
    // -> 1.0 (connected)
    float s = 1.0 / static_cast<float>(dist);
    return (1.0 - s) * m_uncon_attr + s * m_con_attr;
}
