#include "graph_test.h"
#include "graph/graph.h"

#include <sstream>

using namespace godot;

void GraphTest::_register_methods()
{
    register_method("_ready", &GraphTest::_ready);
}

void GraphTest::_init()
{
}

void GraphTest::_ready()
{
#include "graph_input.h"

    int n, m;
    input >> n >> m;

    std::vector<std::set<int>> adj(n + 1);
    for(int i {0}; i <= m; ++i) {
        int a, b;
        input >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    std::stringstream out;
    for(int i {1}; i <= n; ++i) {
        out << i << ": ";
        for(int e: adj[i]) {
            out << e << ", ";
        }
        out << std::endl;
    }
    prt(out.str());

    Graph* graph = get_node<Graph>("Graph");
    graph->set_adjacency_list(adj, n);
}
