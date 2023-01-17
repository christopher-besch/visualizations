#include "graph.h"
#include "PoolArrays.hpp"

using namespace godot;

void Graph::_register_methods()
{
    register_method("_ready", &Graph::_ready);
}

Graph::Graph() {}
Graph::~Graph() {}

void Graph::_init() {}

void Graph::_ready()
{
    Godot::print("hi");
}
