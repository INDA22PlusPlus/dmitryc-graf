#include <iostream>
#include <queue>
#include <climits>
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

struct CompareEdges {
    bool operator()(Edge& v1, Edge& v2)
    {
        return v1.weight < v2.weight;
    }
};

class Vertex {
public:
    priority_queue<Edge, vector<Edge>, CompareEdges> edges;
    long long distance = LLONG_MAX;
    long long id;

    Vertex() {
        this->id = 0;
    }

    explicit Vertex(long long id) {
        this->id = id;
    }
};

struct CompareDistances {
    bool operator()(Vertex& v1, Vertex& v2)
    {
        return v1.distance < v2.distance;
    }
};

// TODO: Fix vectors to arrays
class Graph {
public:
    vector<Vertex> vertices;

    explicit Graph(long long vertices_amount) {
        this->vertices = vector<Vertex>(vertices_amount);

        // TODO: Fix this
        for (long long i = 0; i < vertices_amount; i++) {
            this->vertices[i].id = i;
        }
    }

    // Adds edges from cin input
    void add_edges_from_input(long long edges, bool print=false) {
        // TODO: Loop without i
        for (int i = 0; i < edges; i++) {
            long long vertex_from, vertex_to, weight;
            cin >> vertex_from >> vertex_to >> weight;
            vertices[vertex_from].edges.push(Edge(vertex_to, weight));

            // TODO: Won't work here, cold fix later but probably no use
            if (print) {
                Edge last = vertices[vertex_from].edges.top();
                cout << vertex_from << " " << last.vertex << " " << last.weight << endl;
            }
        }
    }

    // Computes the shortest distance to vertices in the graph using Prim's Algorithm
    void prim() {
        Vertex& start = vertices[0];
        start.distance = 0;
//        priority_queue<Vertex, vector<Vertex>, CompareDistances> pq;
//        pq.push(start);

        vector<Vertex> tree;
        tree.push_back()

        while (tree.size() == vertices.size()) {

        }


//        while (tree.size() == vertices.size()) {
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

    // Prints out distances from queries to vertices, beginning with starting vertex.
    // Prints "Impossible" if the distance cannot be reached, otherwise prints the distance to the vertex.
    void print_distances() {
//        for (long long query: queries) {
//            long long distance = vertices[query].distance;
//            if (distance == LLONG_MAX) {
//                cout << "Impossible" << endl;
//            } else {
//                cout << distance << endl;
//            }
//        }
    }
};

// Runs Prim's algorithm for all graphs
void run_prim_multiple_graphs(vector<Graph>& graphs) {
    for (Graph& graph: graphs) {
        graph.prim();
    }
}

// Prints out distances for all graphs
void print_distances_multiple_graphs(const vector<Graph>& graphs) {
    for (int i = 0; i < graphs.size(); i++) {
        Graph graph = graphs[i];
        graph.print_distances();

        // TODO: Fix this
        if (i < graphs.size() - 1) {
            cout << endl;
        }
    }
}

// Constructs graphs based on input from cin
vector<Graph> get_graphs_from_input(bool print=false) {
    vector<Graph> graphs;

    while (true) {
        long long vertices_amount, edges;
        cin >> vertices_amount >> edges;
        if (vertices_amount == 0 and edges == 0) {
            break;
        }
        Graph graph = Graph(vertices_amount);
        graph.add_edges_from_input(edges, print);
        graphs.push_back(graph);
    }

    return graphs;
}

int main() {
    vector<Graph> graphs = get_graphs_from_input(false);
    run_prim_multiple_graphs(graphs);
    print_distances_multiple_graphs(graphs);

    return 0;
}
