#include <iostream>
#include <algorithm>
using namespace std;

#define V 4   // Number of cities

int tsp(int graph[V][V], int s) {
    int vertex[V - 1];
    int k = 0;

    // Store all vertices except starting vertex
    for (int i = 0; i < V; i++) {
        if (i != s)
            vertex[k++] = i;
    }

    int min_path = INT_MAX;

    // Generate all permutations
    do {
        int current_pathweight = 0;
        int j = s;

        for (int i = 0; i < V - 1; i++) {
            current_pathweight += graph[j][vertex[i]];
            j = vertex[i];
        }

        current_pathweight += graph[j][s];

        min_path = min(min_path, current_pathweight);

    } while (next_permutation(vertex, vertex + V - 1));

    return min_path;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    cout << "Minimum Travelling Cost: "
         << tsp(graph, 0);

    return 0;
}
