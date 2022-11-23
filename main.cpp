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

// TODO: Fix vectors to arrays
class Graph {
public:
    vector<Vertex> vertices;
    vector<long long> quires;
    long long starting_vertex;

//    Graph() {
//        get_graph_from_input();
//    }
//
    Graph(long long vertices_amount, long long quires, long long starting_vertex) {
        this->vertices = vector<Vertex>(vertices_amount);
        this->quires = vector<long long>(quires);
        this->starting_vertex = starting_vertex;
    }

    void add_edges_and_quires_from_input(long long edges, long long quires_amount) {
//        Graph graph = Graph(vertices_amount, edges);

        // TODO: Loop without i
        for (int i = 0; i < edges; i++) {
            long long vertex_from, vertex_to, weight;
            cin >> vertex_from >> vertex_to >> weight;
            vertices[vertex_from].edges.emplace_back(Edge(vertex_to, weight));

            Edge last = vertices[vertex_from].edges.back();
            cout << vertex_from << " " << last.vertex << " " << last.weight << endl;
        }

        // TODO: Loop without i
        for (int i = 0; i < quires_amount; i++) {
            long long query;
            cin >> query;
            quires[i] = query;
            cout << quires[i] << endl;
        }
    }
};

vector<Graph> get_graphs_from_input() {
    vector<Graph> graphs;

    while (true) {
        long long vertices_amount, edges, quires_amount, starting_vertex;
        cin >> vertices_amount >> edges >> quires_amount >> starting_vertex;
        if (vertices_amount == 0 and edges == 0 and quires_amount == 0 and starting_vertex == 0) {
            break;
        }
        Graph graph = Graph(vertices_amount, quires_amount, starting_vertex);
        graph.add_edges_and_quires_from_input(edges, quires_amount);
        graphs.push_back(graph);
    }

    return graphs;
}

int main() {
//    std::priority_queue<Edge> pq;

    vector<Graph> graphs = get_graphs_from_input();

//    cout << endl << "Hello, World!" << endl;
    return 0;
}
