#pragma once

#include "graph/graph_node.h"
#include "helper.h"

#include <Godot.hpp>
#include <Node2D.hpp>
#include <vector>

namespace godot {
class GraphEdges: public Node2D {
    GODOT_CLASS(GraphEdges, Node2D);

private:
    const std::vector<GraphNode*>* m_nodes {nullptr};

public:
    static void _register_methods();

    GraphEdges() {}
    ~GraphEdges() {}

    void set_nodes(const std::vector<GraphNode*>* nodes)
    {
        m_nodes = nodes;
    }

    void _init();
};
} // namespace godot
