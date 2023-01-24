#pragma once

#include "graph/graph.h"
#include "helper.h"

#include <Camera2D.hpp>
#include <Godot.hpp>
#include <Node2D.hpp>
#include <ViewportContainer.hpp>

namespace godot {
class Warshall: public Node2D {
    GODOT_CLASS(Warshall, Node2D)

private:
    ViewportContainer* m_graph_viewport_container {nullptr};
    Graph*             m_graph {nullptr};
    Camera2D*          m_camera {nullptr};

    float m_bar_width {200.0f};

public:
    static void _register_methods();

    Warshall() {};
    ~Warshall() {};

    void _init();
    void _ready();
    void _process(float delta);

private:
    void reset_graph();
};

} // namespace godot
