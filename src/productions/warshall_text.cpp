#include "warshall.h"

using namespace godot;

String Warshall::get_slide_text(int slide_idx)
{
    switch(slide_idx) {
    case 0:
        return R"(This is a graph. It is defined by a set of nodes and edges. Think of them as towns and roads between them. There are no one way streets so the graph is undirected.
You can describe the graph using an adjacency matrix. Each cell in the adjacency matrix is either 1 or 0. When the cell in the i-th column and j-th row is 1, there is an edge from the i-th to the j-th node in the graph. When it is 0 there is no edge.
Fun Fact: In the case of an undirected graph this is a symmetric matrix.)";
    case 1:
        return R"(Now say you wanted to calculate the minimum path length between node a and node b. The path length is the amount of edges on the path—not the amount of nodes.
And now say you wanted to calculate this path length for any two nodes a and b. This results in a distance matrix, with the value in the i-th column and j-th row containing the path length from node i and j. If there is no path between these nodes, the value is inf.

The Floyd-Warshall algorithm populates an initial distance matrix with 0 on the diagonal (when you have reached node b in 10 steps, you could also reach it in 11), 1 wherever there is a 1 in the adjacency matrix, and inf everywhere else.
The inf values represent a non-existent path with one that takes infinitely long to traverse.)";
    case 2:
        return R"(Now the algorithm goes through all nodes k and checks for all other nodes a and b if the path from a to b can be shortened using k. If the path from a to k plus the path from k to b is shorter than the path that is already in the distance matrix (from a to b without using k), the matrix gets updated.

Once you have done that for every node k, you end up with the desired distance matrix.)";
    case 3:
        return R"(But what if you are not satisfied with the mere path length and want to know exactly what edges to take to get from a to b? This can also be done using the Floyd-Warshall algorithm, we only need to modify it slightly. We create a second matrix, a next node matrix. It's value in the i-th column and j-th row represents the index of the node you need to go to next when you are at node i and want to get to node j. If there is no path from i to j the value is -1.
So to get all nodes on the path from node a to b, you need to do this:

c := a
add c to path
while (c != b) {
    c = value in c-th column and b-th row
    add c to path
})";
    case 4:
        return R"(Now onto calculating the next node matrix. Start with the diagonal being populated with it's column index (when you are at node a and want to go to node a, go to node a). Additionally everywhere there is a 1 in the adjacency matrix set the value in the i-th column and j-th row to j (when you are at node i, want to get to j and there is a node from i to j, go to j). Everywhere else set it to -1.
We go through the Floyd-Warshall algorithm as usual and every time node k is used to shorten the path from a to b, you need to get to k first when you are in a and want to go to b. So the next node matrix in the a-th column and b-th row gets updated with the value in the a-th column and k-th row.)";
    case 5:
        return R"(Now we have calculated every path. Set a target node b below and hover over any node a to highlight the path from a to b.

This is the end of our little adventure. You can change the size of the graph below and let the algorithm calculate the paths again.)";
    default:
        throw "invalid slide_idx";
    }
}
