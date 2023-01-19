#pragma once

#include "camera2d_ctrl.h"
#include "graph/graph.h"
#include "helper.h"

#include <set>
#include <vector>

#include <Godot.hpp>
#include <Node2D.hpp>

namespace godot {
class GraphTest: public Node2D {
    GODOT_CLASS(GraphTest, Node2D)

private:
    Camera2DCtrl* m_camera {nullptr};
    Graph*        m_graph {nullptr};

public:
    static void _register_methods();

    GraphTest() {};
    ~GraphTest() {};

    void _init();
    void _ready();
    void _process(float delta);
};

} // namespace godot
