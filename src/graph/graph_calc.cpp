#include "graph.h"

#include <set>
#include <sstream>
#include <string>
#include <vector>

#include <Object.hpp>
#include <PackedScene.hpp>
#include <ResourceLoader.hpp>

using namespace godot;

void Graph::position_nodes()
{
    int n = m_adj.size();
    // allign nodes in circle at first
    float   circumferance = n * m_node_radius * 4;
    float   angular_step  = (2 * M_PI) / n;
    float   radius        = circumferance / (2 * M_PI);
    Vector2 radial        = Vector2::ONE * radius;

    // go through order and set pos in circle
    for(int pos_idx {0}; pos_idx < n; ++pos_idx) {
        int node_idx = m_order[pos_idx];
        m_nodes[node_idx]->set_target_pos(get_position() + radial.rotated(angular_step * pos_idx));
    }
}

void Graph::calc_paths()
{
    int n      = m_adj.size();
    m_dist_mat = distance_matrix(n, std::vector<int>(n, 0));
    m_path_mat = distance_matrix(n, std::vector<int>(n, -1));
    for(int i {0}; i < n; ++i) {
        for(int j {0}; j < n; ++j) {
            if(i == j) {
                m_dist_mat[i][j] = 0;
                m_path_mat[i][j] = j;
            }
            else if(m_adj[i].count(j) != 0) {
                m_dist_mat[i][j] = 1;
                m_path_mat[i][j] = j;
            }
            else {
                m_dist_mat[i][j] = iinf;
                m_path_mat[i][j] = -1;
            }
        }
    }

    for(int k {0}; k < n; ++k) {
        for(int i {0}; i < n; ++i) {
            for(int j {0}; j < n; ++j) {
                int new_dist = m_dist_mat[i][k] + m_dist_mat[k][j];
                if(new_dist < m_dist_mat[i][j]) {
                    m_dist_mat[i][j] = new_dist;
                    m_path_mat[i][j] = m_path_mat[i][k];
                }
            }
        }
    }
}

void Graph::sort_dfs(std::vector<bool>& visited, int cur)
{
    if(visited[cur])
        return;
    visited[cur] = true;
    for(int e: m_adj[cur])
        sort_dfs(visited, e);
    m_order.push_back(cur);
}

void Graph::calc_order()
{
    std::vector<bool> visited(m_nodes.size(), false);
    m_order = std::vector<int>();
    for(int i {0}; i < m_nodes.size(); ++i)
        sort_dfs(visited, i);
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

float Graph::calc_attr(int dist) const
{
    if(dist == 0)
        return 0.0;

    // -> 0.0 (unconnected)
    // -> 1.0 (connected)
    float s = 1.0 / static_cast<float>(dist);
    return (1.0 - s) * m_uncon_attr + s * m_con_attr;
}
