#include "graph_edges.h"

using namespace godot;
void GraphEdges::_register_methods()
{
    register_method("_process", &GraphEdges::_process);
    register_method("_draw", &GraphEdges::_draw);
}

void GraphEdges::_init()
{
    prt("hi");
}

void GraphEdges::_process(float delta)
{
    update();
}

void GraphEdges::_draw()
{
    for(int i {0}; i < m_nodes->size(); ++i) {
        for(int o: (*m_adj)[i]) {
            draw_line((*m_nodes)[i]->get_position(), (*m_nodes)[o]->get_position(), Color(1.0, 1.0, 1.0, 1.0), 2.0);
        }
    }
}
