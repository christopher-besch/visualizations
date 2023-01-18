#include "camera2d_ctrl.h"

#include <Input.hpp>
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
    // TODO: add property
    m_zoom_factor = 1.1;
    m_max_zoom    = 5.0;
    m_min_zoom    = 0.01;
    m_cur_zoom    = 1.0;
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

    if(input->is_action_just_released("zoom_in")) {
        m_cur_zoom = std::clamp(m_cur_zoom * m_zoom_factor, m_min_zoom, m_max_zoom);
        set_zoom(Vector2(m_cur_zoom, m_cur_zoom));
    }
    if(input->is_action_just_released("zoom_out")) {
        m_cur_zoom = std::clamp(m_cur_zoom / m_zoom_factor, m_min_zoom, m_max_zoom);
        set_zoom(Vector2(m_cur_zoom, m_cur_zoom));
    }
}
