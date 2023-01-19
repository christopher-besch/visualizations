#include "camera2d_ctrl.h"
#include "graph/graph.h"
#include "graph/graph_node.h"
#include "productions/graph_test.h"

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options* o)
{
    godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options* o)
{
    godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void* handle)
{
    godot::Godot::nativescript_init(handle);
    godot::register_class<godot::Graph>();
    godot::register_class<godot::GraphNode>();
    godot::register_class<godot::Camera2DCtrl>();
    godot::register_class<godot::GraphTest>();
}
