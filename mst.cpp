#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1000005;

//int vertices_amount;
//vector<vector<int>> adj; // adjacency matrix of graph
//const int INF = 1000000000; // weight INF means there is no edge

struct Edge {
    int w = INF, to = -1;
};


int main() {
    int vertices_amount, edges_amount;
    cin >> vertices_amount >> edges_amount;

    while (!(vertices_amount == 0 and edges_amount == 0)) {
        // Getting the input, storing it to graph
        int graph[vertices_amount][vertices_amount];

        // Initialize graph with positive infinity
        for (int y = 0; y < vertices_amount; y++) {
            for (int x = 0; x < vertices_amount; x++) {
                graph[y][x] = INF;
            }
        }

        // Add edges
        for (int edge = 0; edge < edges_amount; edge++) {
            int from, to, weight;
            cin >> from >> to >> weight;
            graph[from][to] = weight;
            graph[to][from] = weight;
        }

        // Sets the diagonal zeros
        // Should be here because the problem sets some graph[i][i] values to not be 0, while expecting 0
        for (int vertex = 0; vertex < vertices_amount; vertex++) {
            graph[vertex][vertex] = 0;
        }

//        for (int y = 0; y < vertices_amount; y++) {
//            for (int x = 0; x < vertices_amount; x++) {
//                cout << graph[y][x] << " ";
//            }
//            cout << endl;
//        }

        // Prim's algorithm

        int total_weight = 0;
        vector<bool> selected(vertices_amount, false);
        vector<Edge> min_e(vertices_amount);
        min_e[0].w = 0;

        vector<pair<int, int>> mst;

        for (int i=0; i < vertices_amount; ++i) {
            int v = -1;
            for (int j = 0; j < vertices_amount; ++j) {
                if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                    v = j;
            }

            if (min_e[v].w == INF) {
                cout << "Impossible" << endl;
                exit(0);
            }

            selected[v] = true;
            total_weight += min_e[v].w;
            if (min_e[v].to != -1) {
//                cout << min_e[v].to << " " << v << endl;
                mst.emplace_back(min_e[v].to, v);
            }

            for (int to = 0; to < vertices_amount; ++to) {
                if (graph[v][to] < min_e[to].w)
                    min_e[to] = {graph[v][to], v};
            }
        }

        cout << total_weight << endl;
        for (pair<int, int> edge: mst) {
            cout << edge.first << " " << edge.second << endl;
        }

        cin >> vertices_amount >> edges_amount;
    }

    return 0;
}

// This code is contributed by rathbhupendra
