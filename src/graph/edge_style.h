#pragma once

#include "helper.h"

#include <Godot.hpp>

namespace godot {
struct EdgeStyle {
    Color color {Color(1.0, 1.0, 1.0)};
    float width {2.0f};
};
} // namespace godot
