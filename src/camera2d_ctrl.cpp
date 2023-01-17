#include "camera2d_ctrl.h"

#include <Input.hpp>

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
        set_zoom(get_zoom() * Vector2(m_zoom_factor, m_zoom_factor));
    }
    if(input->is_action_just_released("zoom_out")) {
        set_zoom(get_zoom() * 1 / Vector2(m_zoom_factor, m_zoom_factor));
    }
}
