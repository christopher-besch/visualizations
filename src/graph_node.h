#pragma once

#include <algorithm>

#include <Color.hpp>
#include <Godot.hpp>
#include <Label.hpp>
#include <Node2D.hpp>

namespace godot {
class GraphNode: public Node2D {
    GODOT_CLASS(GraphNode, Node2D)

private:
    float  m_radius;
    float  m_width;
    Color  m_fill_color;
    Color  m_stroke_color;
    String m_text;
    Label* m_label;

private:
    int64_t get_point_count()
    {
        return std::max(m_radius * 1.0, 3.0);
    }

public:
    static void _register_methods();

    float  get_radius() { return m_radius; }
    float  get_width() { return m_width; }
    Color  get_fill_color() { return m_fill_color; }
    Color  get_stroke_color() { return m_stroke_color; }
    String get_text() { return m_text; }

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

    void _init();
    void _ready();
    void _draw();
};

} // namespace godot
