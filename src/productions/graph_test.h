#pragma once

#include "camera2d_ctrl.h"
#include "graph/graph.h"
#include "helper.h"

#include <set>
#include <vector>

#include <Godot.hpp>
#include <Node2D.hpp>
#include <RandomNumberGenerator.hpp>

namespace godot {
class GraphTest: public Node2D {
    GODOT_CLASS(GraphTest, Node2D)

private:
    Camera2DCtrl*          m_camera {nullptr};
    RandomNumberGenerator* m_random;

    Graph*         m_graph {nullptr};
    adjacency_list m_adj;

public:
    static void _register_methods();

    GraphTest() {};
    ~GraphTest() {};

    void _init();
    void _ready();
    void _process(float delta);

private:
    void get_input();

    void get_random_graph(int n);
    void color_edges(int start, int target, Color color, int start_draw = 0);
};

} // namespace godot
