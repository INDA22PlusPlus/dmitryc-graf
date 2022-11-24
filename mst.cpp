#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000005;

struct Edge {
    int vertex = -1;
    int weight = INF;
};

int main() {
    int vertices_amount, edges_amount;
    cin >> vertices_amount >> edges_amount;

    while (!(vertices_amount == 0 and edges_amount == 0)) {
        //// Getting the input, storing it to graph

        // Initialize graph with positive infinity
        vector<vector<int>> graph(vertices_amount, vector<int>(vertices_amount, INF));

        // Add edges from input (Directional graph)
        for (int edge = 0; edge < edges_amount; edge++) {
            int from, to, weight;
            cin >> from >> to >> weight;
            graph[from][to] = weight;
            // Adds mirrored edge (mirrored along 0 diagonal)
            graph[to][from] = weight;
        }

        // Sets the diagonal zeros, in case the problem sets the value vertex something else
        for (int vertex = 0; vertex < vertices_amount; vertex++) {
            graph[vertex][vertex] = 0;
        }

        // Debug graph output
//        for (int y = 0; y < vertices_amount; y++) {
//            for (int x = 0; x < vertices_amount; x++) {
//                cout << graph[y][x] << " ";
//            }
//            cout << endl;
//        }

        //// Prim's algorithm

        // Initializes values for Prim's algorithm
        vector<bool> selected(vertices_amount, false);
        vector<Edge> min_edges(vertices_amount);
        min_edges[0].weight= 0;

        int cost = 0;

        vector<pair<int, int>> mst;

        // Runs Prim's algorithm
        // Loops vertices_amount times
        for (int y = 0; y < vertices_amount; y++) {
            // Sets vertex to negative to indicate starting vertex
            int vertex = -1;
            // Loops through selected
            for (int x = 0; x < vertices_amount; x++) {
                // Checks if vertex isn't selected, then if vertex has initial value or the new value is smaller than
                // the current one resets the vertex to the smaller one
                if (!selected[x] and (vertex == -1 or min_edges[x].weight < min_edges[vertex].weight))
                    vertex = x;
            }

            // Breaks the loop if it's impossible to construct mst
            if (min_edges[vertex].weight == INF) {
                break;
            }

            // Selects the vertex gotten above
            selected[vertex] = true;
            // Adds to the cost of the mst
            cost += min_edges[vertex].weight;
            // Adds vertex to mst if the value isn't the initial one
            if (min_edges[vertex].vertex != -1) {
                // Sorts the input so that the first is the smaller one
                // TODO: Better ways?
                if (min_edges[vertex].vertex < vertex) {
                    mst.emplace_back(min_edges[vertex].vertex, vertex);
                } else {
                    mst.emplace_back(vertex, min_edges[vertex].vertex);
                }
            }

            // Adds edges to min_edge if the new ones have a smaller weight
            for (int to = 0; to < vertices_amount; to++) {
                if (graph[vertex][to] < min_edges[to].weight)
                    min_edges[to] = {vertex, graph[vertex][to]};
            }
        }

        // Prints out the mst if possible with edges, otherwise prints "Impossible"
        if (!mst.empty()) {
            // Prints the mst cost
            cout << cost << endl;

            // Sorts the mst for the right output
            sort(mst.begin(), mst.end());

            // Outputs the sorted mst
            for (pair<int, int> edge: mst) {
                cout << edge.first << " " << edge.second << endl;
            }
        } else {
            cout << "Impossible" << endl;
        }

        cin >> vertices_amount >> edges_amount;
    }

    return 0;
}