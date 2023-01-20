#pragma once

#include "graph_edges.h"
#include "graph_node.h"
#include "helper.h"

#include <set>
#include <vector>

#include <Godot.hpp>
#include <Node2D.hpp>
#include <PackedScene.hpp>

namespace godot {
class Graph: public Node2D {
    GODOT_CLASS(Graph, Node2D)

private:
    Ref<PackedScene>        m_graph_node_scene;
    std::vector<GraphNode*> m_nodes;
    adjacency_list          m_adj;
    distance_matrix         m_dist_mat;
    float                   m_node_radius;
    float                   m_con_attr;
    float                   m_uncon_attr;
    GraphEdges*             m_edges {nullptr};

public:
    static void _register_methods();

    Graph() {};
    ~Graph() {};

    float get_con_attr() const
    {
        return m_con_attr;
    }
    float get_uncon_attr() const
    {
        return m_uncon_attr;
    }
    void set_con_attr(float attr)
    {
        m_con_attr = std::max(attr, 0.0f);
        apply_attractions();
    }
    void set_uncon_attr(float attr)
    {
        m_uncon_attr = std::max(attr, 0.0f);
        apply_attractions();
    }

    void reset_physics();
    void reset();

    void set_zero_based_adjacency_list(const adjacency_list& adj);
    void set_one_based_adjacency_list(const adjacency_list& adj);
    void calc_dist_mat();

    const std::vector<GraphNode*>* get_nodes() const
    {
        return &m_nodes;
    }

    Vector2 get_center_of_mass() const;
    // center, size
    std::pair<Vector2, Vector2> get_bounding_rect() const;
    std::pair<Vector2, Vector2> get_pleasant_bounding_rect() const
    {
        auto [center, size] = get_bounding_rect();
        return {center, size + 1.0 * m_node_radius * Vector2::ONE};
    }

    void _init();
    void _ready();

private:
    GraphNode* instance_graph_node()
    {
        return Object::cast_to<GraphNode>(m_graph_node_scene->instance());
    }

    void apply_attractions();

    void free_nodes();

    float calc_attr(int dist) const;
};

} // namespace godot
