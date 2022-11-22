#include <iostream>
#include <queue>
using namespace std;

class Edge {
public:
    long long vertex;
    long long weight;

    Edge(long long vertex, long long weight) {
        this->vertex = vertex;
        this->weight = weight;
    }
};

class Vertex {
public:
    vector<Edge> edges;
};

//class Graph {
//public:
//    Vertex verices[];
//};

int main() {
//    std::priority_queue<Edge> pq;

    while (true) {
        long long vertices, edges, amount_of_quires, starting_vertex;
        cin >> vertices >> edges >> amount_of_quires >> starting_vertex;
        if (vertices == 0 and edges == 0 and amount_of_quires == 0 and starting_vertex == 0) {
            break;
        }

        Vertex graph [vertices];
        int quires [amount_of_quires];

        // TODO: Loop without i
        for (int i = 0; i < edges; i++) {
            long long vertex_from, vertex_to, weight;
            cin >> vertex_from >> vertex_to >> weight;
            graph[vertex_from].edges.emplace_back(vertex_to, weight);
//        Edge last = graph[vertex_from].edges.back();
//        cout << endl << last.vertex << last.weight;
        }

        // TODO: Loop without i
        for (int i = 0; i < amount_of_quires; i++) {
            cin >> quires[i];
            cout << quires[i] << endl;
        }
    }

//    cout << endl << "Hello, World!" << endl;
    return 0;
}
