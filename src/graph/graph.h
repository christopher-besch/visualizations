#pragma once

#include "edge_style.h"
#include "graph_node.h"
#include "helper.h"

#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

#include <Godot.hpp>
#include <Node2D.hpp>
#include <PackedScene.hpp>
#include <RandomNumberGenerator.hpp>

namespace godot {
class Graph: public Node2D {
    GODOT_CLASS(Graph, Node2D)

private:
    Ref<PackedScene>       m_graph_node_scene;
    RandomNumberGenerator* m_random;

    std::vector<GraphNode*> m_nodes;
    // [from][to]
    std::vector<std::vector<EdgeStyle>> m_edge_styles;

    adjacency_list  m_adj;
    distance_matrix m_dist_mat;
    // [i][j] gives id of next node to go to when you want to get from i to j
    distance_matrix  m_path_mat;
    std::vector<int> m_order;

    float m_node_radius;
    float m_con_attr;
    float m_uncon_attr;

public:
    static void _register_methods();

    Graph() {};
    ~Graph() {};

    void _init();
    void _ready();
    void _process();
    void _draw();

    Color get_edge_color(int from, int to) const { return m_edge_styles[from][to].color; }
    float get_edge_width(int from, int to) const { return m_edge_styles[from][to].width; }
    void  set_edge_color(int from, int to, Color color) { m_edge_styles[from][to].color = color; }
    void  set_edge_width(int from, int to, float width) { m_edge_styles[from][to].width = width; }

    const adjacency_list&  get_adj() const { return m_adj; }
    const distance_matrix& get_dist_mat() const { return m_dist_mat; }
    const distance_matrix& get_path_mat() const { return m_path_mat; }
    GraphNode*             get_node(int idx) { return m_nodes[idx]; }

    float get_con_attr() const { return m_con_attr; }
    float get_uncon_attr() const { return m_uncon_attr; }
    void  set_con_attr(float attr)
    {
        m_con_attr = std::max(attr, 0.0f);
        apply_attractions();
    }
    void set_uncon_attr(float attr)
    {
        m_uncon_attr = std::max(attr, 0.0f);
        apply_attractions();
    }

    // evict prior data and use current m_adj to recalculate everything
    void reset();
    void position_nodes();
    void set_zero_based_adjacency_list(const adjacency_list& adj);
    void set_one_based_adjacency_list(const adjacency_list& adj);

    Vector2 get_center_of_mass() const;
    // center, size
    std::pair<Vector2, Vector2> get_bounding_rect() const;
    std::pair<Vector2, Vector2> get_pleasant_bounding_rect() const
    {
        auto [center, size] = get_bounding_rect();
        return {center, size + 5.0 * m_node_radius * Vector2::ONE};
    }

    void set_random_adj(int n);

private:
    void calc_paths();
    void calc_order();

    GraphNode* instance_graph_node()
    {
        return Object::cast_to<GraphNode>(m_graph_node_scene->instance());
    }
    void free_nodes_edges();
    void apply_attractions();

    float calc_attr(int dist) const;
    void  sort_dfs(std::vector<bool>& visited, int cur);
};

} // namespace godot
