#pragma once

#include <Camera2D.hpp>
#include <Godot.hpp>
#include <Vector2.hpp>

namespace godot {
class Camera2DCtrl: public Camera2D {
    GODOT_CLASS(Camera2DCtrl, Node2D)

private:
    float m_zoom_factor;
    float m_max_zoom;
    float m_min_zoom;
    float m_cur_zoom;

    Vector2 m_mouse_click_pos;
    Vector2 m_camera_click_pos;

public:
    static void _register_methods();

    Camera2DCtrl() {}
    ~Camera2DCtrl() {}

    void _init();
    void _process(float delta);
};

} // namespace godot