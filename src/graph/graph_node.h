#pragma once

#include "helper.h"

#include <algorithm>
#include <unordered_map>

#include <CircleShape2D.hpp>
#include <CollisionShape2D.hpp>
#include <Color.hpp>
#include <Godot.hpp>
#include <Label.hpp>
#include <RandomNumberGenerator.hpp>
#include <RigidBody2D.hpp>

namespace godot {
class GraphNode: public RigidBody2D {
    GODOT_CLASS(GraphNode, RigidBody2D)

private:
    float                                 m_radius;
    float                                 m_width;
    Color                                 m_fill_color;
    Color                                 m_stroke_color;
    String                                m_text;
    Label*                                m_label {nullptr};
    CollisionShape2D*                     m_collision {nullptr};
    CircleShape2D*                        m_collision_shape {nullptr};
    RandomNumberGenerator*                m_random;
    std::unordered_map<GraphNode*, float> m_attractors;

public:
    static void _register_methods();

    GraphNode() {}
    ~GraphNode() {}

    float  get_radius() const { return m_radius; }
    float  get_width() const { return m_width; }
    Color  get_fill_color() const { return m_fill_color; }
    Color  get_stroke_color() const { return m_stroke_color; }
    String get_text() const { return m_text; }

    void set_radius(float radius)
    {
        m_radius = radius;
        update();
    }
    void set_width(float width)
    {
        m_width = width;
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

    void add_attractor(GraphNode* node, float target_distance)
    {
        m_attractors[node] = target_distance;
        update();
    }

    void remove_attractor(GraphNode* node)
    {
        m_attractors.erase(node);
        update();
    }

    const std::unordered_map<GraphNode*, float>& get_attractors() const
    {
        return m_attractors;
    }

    void _init();
    void _ready();
    void _draw();
    void _physics_process(float delta);
};

} // namespace godot
