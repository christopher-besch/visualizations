#include <cmath>

#include "Vector2.hpp"
#include "graph_node.h"

using namespace godot;

void GraphNode::_register_methods()
{
    register_method("_ready", &GraphNode::_ready);
    register_method("_draw", &GraphNode::_draw);
    register_method("_physics_process", &GraphNode::_physics_process);
    register_property<GraphNode, float>("radius", &GraphNode::set_radius, &GraphNode::get_radius, 20.0);
    register_property<GraphNode, float>("width", &GraphNode::set_width, &GraphNode::get_width, 2.0);
    register_property<GraphNode, Color>("fill_color", &GraphNode::set_fill_color, &GraphNode::get_fill_color, Color(0.0, 0.0, 0.0));
    register_property<GraphNode, Color>("stroke_color", &GraphNode::set_stroke_color, &GraphNode::get_stroke_color, Color(1.0, 1.0, 1.0));
    register_property<GraphNode, String>("text", &GraphNode::set_text, &GraphNode::get_text, "Text here");
}

void GraphNode::_init()
{
    m_radius     = 20.0;
    m_width      = 2.0;
    m_fill_color = Color(1.0, 1.0, 1.0);
    m_fill_color = Color(1.0, 1.0, 1.0);
    m_text       = "Text here";

    m_random = RandomNumberGenerator::_new();
    m_random->randomize();
}

void GraphNode::_ready()
{
    m_label           = get_node<Label>("Label");
    m_collision       = get_node<CollisionShape2D>("Collision");
    m_collision_shape = CircleShape2D::_new();
}

void GraphNode::_draw()
{
    draw_circle(Vector2(0.0, 0.0), m_radius, m_fill_color);
    draw_arc(Vector2(0.0, 0.0), m_radius, 0, 2 * M_PI, 20, m_stroke_color, m_width, true);

    m_label->set_text(m_text);

    m_collision_shape->set_radius(m_radius);
    m_collision->set_shape(m_collision_shape);
}

void GraphNode::_physics_process(float delta)
{
    // negate any prior impulse
    apply_central_impulse(-get_linear_velocity() * get_mass());
    // apply force to attractors
    for(auto [other, target_distance]: m_attractors) {
        if(other == this)
            continue;
        Vector2 this_to_other = other->get_position() - get_position();
        float   real_distance = this_to_other.length();
        this_to_other /= real_distance;

        float force;
        if(real_distance == 0.0) {
            force         = 10.0;
            this_to_other = Vector2(1.0, 0.0).rotated(m_random->randf());
        }
        else
            force = real_distance * real_distance / target_distance - target_distance * target_distance / real_distance;
        apply_central_impulse(this_to_other * force);
    }
}
