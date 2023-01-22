#include "camera2d_ctrl.h"
#include "Node.hpp"

#include <Input.hpp>
#include <Viewport.hpp>
#include <algorithm>

using namespace godot;

void Camera2DCtrl::_register_methods()
{
    register_method("_process", &Camera2DCtrl::_process);
}

void Camera2DCtrl::_init()
{
    m_mouse_click_pos  = Vector2 {-1.0, -1.0};
    m_camera_click_pos = Vector2 {-1.0, -1.0};
    m_zoom_factor      = 1.1;
    m_min_zoom         = 0.01;
    m_cur_zoom         = 1.0;
}

void Camera2DCtrl::_process(float delta)
{
    Input* input = Input::get_singleton();

    if(input->is_action_just_pressed("pan_click")) {
        m_mouse_click_pos  = get_local_mouse_position();
        m_camera_click_pos = get_position();
        input->set_mouse_mode(Input::MOUSE_MODE_HIDDEN);
    }
    if(input->is_action_just_released("pan_click")) {
        input->set_mouse_mode(Input::MOUSE_MODE_VISIBLE);
    }
    if(input->is_action_pressed("pan_click")) {
        Vector2 mouse_delta = get_local_mouse_position() - m_mouse_click_pos;
        Vector2 new_pos     = m_camera_click_pos - mouse_delta;
        set_position(new_pos);
    }

    if(input->is_action_just_released("zoom_in"))
        set_cur_zoom(m_cur_zoom * m_zoom_factor);
    if(input->is_action_just_released("zoom_out"))
        set_cur_zoom(m_cur_zoom / m_zoom_factor);
    set_zoom(Vector2(m_cur_zoom, m_cur_zoom));
}

void Camera2DCtrl::zoom_to_rect(std::pair<Vector2, Vector2> rect)
{
    Vector2 center  = rect.first;
    Vector2 size    = rect.second;
    Vector2 vp_size = get_viewport()->get_size();

    float zoom = std::max(size.x / vp_size.x, size.y / vp_size.y);
    set_cur_zoom(zoom);
    set_position(center);
}
