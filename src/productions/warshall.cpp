#include "warshall.h"

#include <Input.hpp>

#include <Viewport.hpp>
#include <cmath>
#include <sstream>

using namespace godot;

void Warshall::_register_methods()
{
    register_method("_ready", &Warshall::_ready);
    register_method("_process", &Warshall::_process);
}

void Warshall::_init()
{
}

void Warshall::_ready()
{
    m_graph_viewport_container = get_node<ViewportContainer>("GraphViewportContainer");
    m_graph                    = get_node<Graph>("Graph");
    m_camera                   = get_node<Camera2D>("Camera");
}

void Warshall::_process(float delta)
{
    Input* input = Input::get_singleton();

    Vector2 root_vp_size = get_viewport()->get_size();
    m_graph_viewport_container->set_size(Vector2(root_vp_size.x - m_bar_width, root_vp_size.y / 2));
}

void Warshall::reset_graph()
{
}
