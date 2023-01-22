#include <cmath>

#include "Vector2.hpp"
#include "graph_node.h"

using namespace godot;

void GraphNode::_register_methods()
{
    register_method("_ready", &GraphNode::_ready);
    register_method("_draw", &GraphNode::_draw);
    register_method("_physics_process", &GraphNode::_physics_process);
    register_method("_integrate_forces", &GraphNode::_integrate_forces);
}

void GraphNode::_init()
{
    m_random = RandomNumberGenerator::_new();
    m_random->randomize();
    m_collision_shape = CircleShape2D::_new();
}

void GraphNode::_ready()
{
    m_label     = get_node<Label>("Label");
    m_collision = get_node<CollisionShape2D>("Collision");
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
    // apply force from attractors
    for(int i {0}; i < m_all_nodes->size(); ++i) {
        if(i == m_this_idx)
            continue;
        GraphNode* other           = (*m_all_nodes)[i];
        float      target_distance = m_attractions[i];
        if(target_distance < 0.01)
            continue;

        Vector2 this_to_other = other->get_position() - get_position();
        float   real_distance = this_to_other.length();
        this_to_other /= real_distance;

        // touching? -> let physics engine care about pushing apart -> keeps everything from exploding
        if(real_distance < m_radius + other->m_radius - 2.0f)
            continue;

        float force = real_distance * real_distance / target_distance - target_distance * target_distance / real_distance;
        // scale with inverse amount of other nodes
        force /= m_all_nodes->size() - 1;
        apply_central_impulse(this_to_other * force);
    }
}

void GraphNode::_integrate_forces(Physics2DDirectBodyState* state)
{
    if(m_update_pos) {
        Transform2D trans = state->get_transform();
        trans.set_origin(m_target_pos);
        state->set_transform(trans);
        m_update_pos = false;
    }
}
