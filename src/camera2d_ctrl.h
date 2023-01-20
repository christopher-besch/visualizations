#pragma once
#include "helper.h"

#include <Camera2D.hpp>
#include <Godot.hpp>
#include <Vector2.hpp>

namespace godot {
class Camera2DCtrl: public Camera2D {
    GODOT_CLASS(Camera2DCtrl, Node2D)

private:
    float m_zoom_factor;
    float m_min_zoom;
    float m_cur_zoom;

    Vector2 m_mouse_click_pos;
    Vector2 m_camera_click_pos;

public:
    static void _register_methods();

    Camera2DCtrl() {}
    ~Camera2DCtrl() {}

    float get_cur_zoom() const
    {
        return m_cur_zoom;
    }
    void set_cur_zoom(float zoom)
    {
        m_cur_zoom = std::max(zoom, m_min_zoom);
    }

    void zoom_to_rect(std::pair<Vector2, Vector2> rect);

    void _init();
    void _process(float delta);
};

} // namespace godot
