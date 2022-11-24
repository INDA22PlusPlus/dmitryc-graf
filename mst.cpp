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

int main() {
    int vertices_amount, edges_amount;
    cin >> vertices_amount >> edges_amount;

    while (!(vertices_amount == 0 and edges_amount == 0)) {
        // Getting the input, storing it to graph
        int graph[vertices_amount][vertices_amount];

        // Initialize graph with positive infinity
        for (int y = 0; y < vertices_amount; y++) {
            for (int x = 0; x < vertices_amount; x++) {
                graph[y][x] = 0;
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

        // Prim's Algorithm
        int no_edge;  // number of edge

        // create an array to track selected vertex
        // selected will become true otherwise false
        int selected[vertices_amount];

        // set selected false initially
        memset(selected, false, sizeof(selected));

        // set number of edge to 0
        no_edge = 0;

        // the number of edges in minimum spanning tree will be
        // always less than (V -1), where V is number of vertices in
        //graph

        // choose 0th vertex and make it true
        selected[0] = true;

        int x;  //  row number
        int y;  //  col number

        // print for edge and weight
        cout << "Edge"
             << " : "
             << "Weight";
        cout << endl;
        while (no_edge < vertices_amount - 1) {
            //For every vertex in the set S, find the all adjacent vertices
            // , calculate the distance from the vertex selected at step 1.
            // if the vertex is already in the set S, discard it otherwise
            //choose another vertex nearest to selected vertex  at step 1.

            int min = INF;
            x = 0;
            y = 0;

            for (int i = 0; i < vertices_amount; i++) {
                if (selected[i]) {
                    for (int j = 0; j < vertices_amount; j++) {
                        if (!selected[j] && graph[i][j]) {  // not in selected and there is an edge
                            if (min > graph[i][j]) {
                                min = graph[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }
            cout << x << " - " << y << " :  " << graph[x][y];
            cout << endl;
            selected[y] = true;
            no_edge++;
        }

        cin >> vertices_amount >> edges_amount;
    }


    return 0;
}
