#pragma once

#include <Godot.hpp>
#include <Node2D.hpp>
#include <RandomNumberGenerator.hpp>
#include <ViewportContainer.hpp>

namespace godot {
class Warshall: public Node2D {
    GODOT_CLASS(Warshall, Node2D)

private:
    RandomNumberGenerator* m_random;
    ViewportContainer*     m_graph_viewport_container;

    float m_bar_width {200.0f};

public:
    static void _register_methods();

    Warshall() {};
    ~Warshall() {};

    void _init();
    void _ready();
    void _process(float delta);
};

} // namespace godot
