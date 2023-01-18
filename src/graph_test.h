#pragma once

#include "helper.h"

#include <set>
#include <vector>

#include <Godot.hpp>
#include <Node2D.hpp>

namespace godot {
class GraphTest: public Node2D {
    GODOT_CLASS(GraphTest, Node2D)

public:
    static void _register_methods();

    GraphTest() {};
    ~GraphTest() {};

    void _init();
    void _ready();
};

} // namespace godot
