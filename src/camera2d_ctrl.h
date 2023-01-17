#pragma once

#include <Camera2D.hpp>
#include <Godot.hpp>
#include <Vector2.hpp>

namespace godot {
class Camera2DCtrl: public Camera2D {
    GODOT_CLASS(Camera2DCtrl, Node2D)

private:
    float m_zoom_factor;

    Vector2 m_mouse_click_pos;
    Vector2 m_camera_click_pos;

public:
    static void _register_methods();

    void _init();
    void _process(float delta);
};

} // namespace godot
