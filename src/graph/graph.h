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
    float                   m_node_radius;
    GraphEdges*             m_edges {nullptr};

public:
    static void _register_methods();

    Graph() {};
    ~Graph() {};

    void set_adjacency_list(const adjacency_list& adj);
    void set_one_based_adjacency_list(const adjacency_list& adj);

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
};

} // namespace godot
