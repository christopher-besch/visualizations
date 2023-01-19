#pragma once

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
    Ref<PackedScene> m_graph_node_scene;

public:
    static void _register_methods();

    Graph() {};
    ~Graph() {};

    void set_adjacency_list(const adjacency_list& adj, int n);

    void _init();
    void _ready();

private:
    GraphNode* instance_graph_node()
    {
        return Object::cast_to<GraphNode>(m_graph_node_scene->instance());
    }
};

} // namespace godot
