//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//long long INFP = 100000005LL;
//long long INFN = -100000005LL;
//
//
//int main() {
//    int vertices_amount, edges_amount;
//    cin >> vertices_amount >> edges_amount;
//
//    while (!(vertices_amount == 0 and edges_amount == 0)) {
//        // Getting the input, storing it to graph
//        vector<vector<pair<int, int>>> graph(vertices_amount);
//        for (int edge = 0; edge < edges_amount; edge++) {
//            int from, to, weight;
//            cin >> from >> to >> weight;
//            graph[from].push_back({to, weight});
//        }
//
//        // Prim's Algorithm
//
////        while (!pq.empty()) {
////            // TODO: Fix this, had problems with references, solved with sketchy id system so far
////            long long vertex_id = pq.top().id;
////            pq.pop();
////            Vertex& vertex = vertices[vertex_id];
////
////            for (Edge edge: vertex.edges) {
////                long long new_distance = vertex.distance + edge.weight;
////                Vertex& adjacent_vertex = vertices[edge.vertex];
////
////                if (new_distance < adjacent_vertex.distance) {
////                    pq.push(adjacent_vertex);
////                    adjacent_vertex.distance = new_distance;
////                }
////            }
////        }
//    }
//
//}

// Prim's Algorithm in C++

#include <cstring>
#include <iostream>
using namespace std;

int INF = 1000005;

// create a 2d array of size 5x5
//for adjacency matrix to represent graph

//int graph[4][4] = {
//        {0,  9,  75, 0},
//        {9,  0,  95, 19},
//        {75, 95, 0,  51},
//        {0,  19, 51, 0},
//        };

//int main() {
//    int vertices_amount, edges_amount;
//    cin >> vertices_amount >> edges_amount;
//
//    while (!(vertices_amount == 0 and edges_amount == 0)) {
//        // Getting the input, storing it to graph
//        int graph[vertices_amount][vertices_amount];
//
//        // Initialize graph with positive infinity
//        for (int y = 0; y < vertices_amount; y++) {
//            for (int x = 0; x < vertices_amount; x++) {
//                graph[y][x] = 0;
//            }
//        }
//
//        // Add edges
//        for (int edge = 0; edge < edges_amount; edge++) {
//            int from, to, weight;
//            cin >> from >> to >> weight;
//            graph[from][to] = weight;
//            graph[to][from] = weight;
//        }
//
//        // Sets the diagonal zeros
//        // Should be here because the problem sets some graph[i][i] values to not be 0, while expecting 0
//        for (int vertex = 0; vertex < vertices_amount; vertex++) {
//            graph[vertex][vertex] = 0;
//        }
//
//        // Prim's Algorithm
//        int no_edge;  // number of edge
//
//        // create an array to track selected vertex
//        // selected will become true otherwise false
//        int selected[vertices_amount];
//
//        // set selected false initially
//        memset(selected, false, sizeof(selected));
//
//        // set number of edge to 0
//        no_edge = 0;
//
//        // the number of edges in minimum spanning tree will be
//        // always less than (vertices_amount -1), where vertices_amount is number of vertices in
//        //graph
//
//        // choose 0th vertex and make it true
//        selected[0] = true;
//
//        int x;  //  row number
//        int y;  //  col number
//
//        // print for edge and weight
//        cout << "Edge"
//             << " : "
//             << "Weight";
//        cout << endl;
//        while (no_edge < vertices_amount - 1) {
//            //For every vertex in the set S, find the all adjacent vertices
//            // , calculate the distance from the vertex selected at step 1.
//            // if the vertex is already in the set S, discard it otherwise
//            //choose another vertex nearest to selected vertex  at step 1.
//
//            int min = INF;
//            x = 0;
//            y = 0;
//
//            for (int i = 0; i < vertices_amount; i++) {
//                if (selected[i]) {
//                    for (int j = 0; j < vertices_amount; j++) {
//                        if (!selected[j] && graph[i][j]) {  // not in selected and there is an edge
//                            if (min > graph[i][j]) {
//                                min = graph[i][j];
//                                x = i;
//                                y = j;
//                            }
//                        }
//                    }
//                }
//            }
//            cout << x << " - " << y << " :  " << graph[x][y];
//            cout << endl;
//            selected[y] = true;
//            no_edge++;
//        }
//
//        cin >> vertices_amount >> edges_amount;
//    }
//
//
//    return 0;
//}


// A C++ program for Prim's Minimum
// Spanning Tree (MST) algorithm. The program is
// for adjacency matrix representation of the graph
#include <bits/stdc++.h>
using namespace std;

// Driver's code
int main()
{
    /* Let us create the following graph
        2 3
    (0)--(1)--(2)
    | / \ |
    6| 8/ \5 |7
    | / \ |
    (3)-------(4)
            9	 */
//    int graph[vertices_amount][vertices_amount] = { { 0, 2, 0, 6, 0 },
//                        { 2, 0, 3, 8, 5 },
//                        { 0, 3, 0, 0, 7 },
//                        { 6, 8, 0, 0, 9 },
//                        { 0, 5, 7, 9, 0 } };

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

        for (int y = 0; y < vertices_amount; y++) {
            for (int x = 0; x < vertices_amount; x++) {
                cout << graph[y][x] << " ";
            }
            cout << endl;
        }

        // Prim's algorithm

        // Array to store constructed MST
        int parent[vertices_amount];

        // Key values used to pick minimum weight edge in cut
        int key[vertices_amount];

        // To represent set of vertices included in MST
        bool mstSet[vertices_amount];

        // Initialize all keys as INFINITE
        for (int i = 0; i < vertices_amount; i++)
            key[i] = INF * 2, mstSet[i] = false;

        // Always include first 1st vertex in MST.
        // Make key 0 so that this vertex is picked as first
        // vertex.
        key[0] = 0;
        parent[0] = -1; // First node is always root of MST

        // The MST will have vertices_amount vertices
        for (int count = 0; count < vertices_amount - 1; count++) {
            // Pick the minimum key vertex from the
            // set of vertices not yet included in MST
            // Initialize u value
            int u = INF * 2, min_index;

            for (int v = 0; v < vertices_amount; v++)
                if (mstSet[v] == false && key[v] < u)
                    u = key[v], min_index = v;


            // Add the picked vertex to the MST Set
            mstSet[u] = true;

            // Update key value and parent index of
            // the adjacent vertices of the picked vertex.
            // Consider only those vertices which are not
            // yet included in MST
            for (int v = 0; v < vertices_amount; v++)

                // graph[u][v] is non-zero only for adjacent
                // vertices of m mstSet[v] is false for vertices
                // not yet included in MST Update the key only
                // if graph[u][v] is smaller than key[v]
                if (graph[u][v] && mstSet[v] == false
                    && graph[u][v] < key[v])
                    parent[v] = u, key[v] = graph[u][v];
        }

        // print the constructed MST
        cout << "Edge \tWeight\n";
        for (int i = 1; i < vertices_amount; i++)
            cout << parent[i] << " - " << i << " \t"
                 << graph[i][parent[i]] << " \n";

        cin >> vertices_amount >> edges_amount;
    }

    return 0;
}

// This code is contributed by rathbhupendra
