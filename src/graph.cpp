#include "graph.h"
#include "graph_node.h"

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
    GraphNode* graph_node = get_node<GraphNode>("GraphNode");
    graph_node->set_fill_color(Color(0.25, 0.875, 0.8125));
}
