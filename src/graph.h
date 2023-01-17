#pragma once

#include <Godot.hpp>
#include <Node2D.hpp>

namespace godot {
class Graph: public Node2D {
    GODOT_CLASS(Graph, Node2D)

public:
    static void _register_methods();

    Graph();
    ~Graph();

    void _init();
    void _ready();
};

} // namespace godot
