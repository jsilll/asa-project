#include "weighted_graph.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;

    scanf("%d %d", &n, &k);

    int V = n + 2;
    W_Graph g(V);

    // Process <-> Processor edges
    int cpu0_cost, cpu1_cost;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &cpu0_cost, &cpu1_cost);
        g.addEdge(i, V - 2, cpu0_cost);
        g.addEdge(i, V - 1, cpu1_cost);
    }

    // Process <-> Process edges
    int id1, id2, com_cost;
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d %d", &id1, &id2, &com_cost);
        g.addEdge(id1 - 1, id2 - 1, com_cost);
    }

    g.kruskal();

    return 0;
}