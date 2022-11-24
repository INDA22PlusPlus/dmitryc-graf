#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long INFP = 100000005LL;
long long INFN = -100000005LL;


int main() {
    int vertices_amount, edges_amount;
    cin >> vertices_amount >> edges_amount;

    while (!(vertices_amount == 0 and edges_amount == 0)) {
        // Getting the input, storing it to graph
        vector<vector<pair<int, int>>> graph(vertices_amount);
        for (int edge = 0; edge < edges_amount; edge++) {
            int from, to, weight;
            cin >> from >> to >> weight;
            graph[from].push_back({to, weight});
        }

        // Prim's Algorithm
        vector<int> distances(vertices_amount, );
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({});

//        while (!pq.empty()) {
//            // TODO: Fix this, had problems with references, solved with sketchy id system so far
//            long long vertex_id = pq.top().id;
//            pq.pop();
//            Vertex& vertex = vertices[vertex_id];
//
//            for (Edge edge: vertex.edges) {
//                long long new_distance = vertex.distance + edge.weight;
//                Vertex& adjacent_vertex = vertices[edge.vertex];
//
//                if (new_distance < adjacent_vertex.distance) {
//                    pq.push(adjacent_vertex);
//                    adjacent_vertex.distance = new_distance;
//                }
//            }
//        }
    }

}
