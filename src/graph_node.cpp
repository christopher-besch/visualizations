#include <cmath>

#include "Vector2.hpp"
#include "graph_node.h"

using namespace godot;

void GraphNode::_register_methods()
{
    register_method("_draw", &GraphNode::_draw);
    register_method("_ready", &GraphNode::_ready);
    register_property<GraphNode, float>("radius", &GraphNode::set_radius, &GraphNode::get_radius, 100.0);
    register_property<GraphNode, float>("width", &GraphNode::set_width, &GraphNode::get_width, 2.0);
    register_property<GraphNode, Color>("fill_color", &GraphNode::set_fill_color, &GraphNode::get_fill_color, Color(0.0, 0.0, 0.0));
    register_property<GraphNode, Color>("stroke_color", &GraphNode::set_stroke_color, &GraphNode::get_stroke_color, Color(1.0, 1.0, 1.0));
    register_property<GraphNode, String>("text", &GraphNode::set_text, &GraphNode::get_text, "Text here");
}

void GraphNode::_init()
{
    m_radius     = 100.0;
    m_width      = 2.0;
    m_fill_color = Color(1.0, 1.0, 1.0);
    m_fill_color = Color(1.0, 1.0, 1.0);
    m_text       = "Text here";
}

void GraphNode::_ready()
{
    m_label = get_node<Label>("Label");
}

void GraphNode::_draw()
{
    Godot::print((long)m_label);
    draw_circle(Vector2(0.0, 0.0), m_radius, m_fill_color);
    draw_arc(Vector2(0.0, 0.0), m_radius, 0, 2 * M_PI, get_point_count(), m_stroke_color, m_width, true);
    m_label->set_text(m_text);
}
