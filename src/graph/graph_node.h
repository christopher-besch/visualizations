#pragma once

#include "helper.h"

#include <algorithm>
#include <cmath>
#include <unordered_map>

#include <CircleShape2D.hpp>
#include <CollisionShape2D.hpp>
#include <Color.hpp>
#include <Godot.hpp>
#include <Label.hpp>
#include <Physics2DDirectBodyState.hpp>
#include <RandomNumberGenerator.hpp>
#include <RigidBody2D.hpp>

namespace godot {
class GraphNode: public RigidBody2D {
    GODOT_CLASS(GraphNode, RigidBody2D)

private:
    RandomNumberGenerator* m_random;

    float  m_radius;
    float  m_width;
    Color  m_fill_color;
    Color  m_stroke_color;
    String m_text;

    Label*            m_label {nullptr};
    CollisionShape2D* m_collision {nullptr};
    CircleShape2D*    m_collision_shape {nullptr};

    int                      m_this_idx {-1};
    std::vector<GraphNode*>* m_all_nodes {nullptr};
    std::vector<float>       m_attractions;

    Vector2 m_target_pos;
    bool    m_update_pos {false};

public:
    static void _register_methods();

    GraphNode() {}
    ~GraphNode() {}

    float  get_radius() const { return m_radius; }
    Color  get_fill_color() const { return m_fill_color; }
    Color  get_stroke_color() const { return m_stroke_color; }
    String get_text() const { return m_text; }

    void set_radius(float radius)
    {
        m_radius = radius;
        update();
    }
    void set_fill_color(Color fill_color)
    {
        m_fill_color = fill_color;
        update();
    }
    void set_stroke_color(Color stroke_color)
    {
        m_stroke_color = stroke_color;
        update();
    }
    void set_text(String text)
    {
        m_text = text;
        update();
    }

    void set_target_pos(Vector2 pos)
    {
        m_target_pos = pos;
        m_update_pos = true;
    }

    void set_all_nodes(std::vector<GraphNode*>* all_nodes, int this_idx)
    {
        m_this_idx    = this_idx;
        m_all_nodes   = all_nodes;
        m_attractions = std::vector<float>(all_nodes->size(), 0.0);
    }

    void set_attraction(int idx, float attr)
    {
        m_attractions[idx] = attr;
    }

    void _init();
    void _ready();
    void _draw();
    void _physics_process(float delta);
    void _integrate_forces(Physics2DDirectBodyState* state);
};

} // namespace godot
