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
    long long distance = LLONG_MAX;
    long long id;

    Vertex() {
        this->id = 0;
    }

    Vertex(long long id) {
        this->id = id;
    }
//    bool visited = false;
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
    vector<long long> quires;
    long long starting_vertex;
    Graph(long long vertices_amount, long long quires, long long starting_vertex) {
        this->vertices = vector<Vertex>(vertices_amount);
        for (long long i = 0; i < vertices_amount; i++) {
            this->vertices[i].id = i;
        }

        this->quires = vector<long long>(quires);
        this->starting_vertex = starting_vertex;
    }

    void add_edges_from_input(long long edges, bool print=false) {
        // TODO: Loop without i
        for (int i = 0; i < edges; i++) {
            long long vertex_from, vertex_to, weight;
            cin >> vertex_from >> vertex_to >> weight;
            vertices[vertex_from].edges.emplace_back(Edge(vertex_to, weight));

            if (print) {
                Edge last = vertices[vertex_from].edges.back();
                cout << vertex_from << " " << last.vertex << " " << last.weight << endl;
            }
        }
    }

    void add_quires_from_input(long long quires_amount, bool print=false) {
        // TODO: Loop without i
        for (int i = 0; i < quires_amount; i++) {
            long long query;
            cin >> query;
            quires[i] = query;
            if (print){
                cout << quires[i] << endl;
            }
        }
    }

    void add_edges_and_quires_from_input(long long edges, long long quires_amount, bool print=false) {
        add_edges_from_input(edges, print);
        add_quires_from_input(quires_amount, print);
    }

    void dijkstra() {
        Vertex& start = vertices[starting_vertex];
        start.distance = 0;
        priority_queue<Vertex, vector<Vertex>, CompareDistances> pq;
        pq.push(start);

        while (!pq.empty()) {
            // TODO: Fix this, had problems with references, solved with sketchy id system so far
            long long vertex_id = pq.top().id;
            pq.pop();
            Vertex& vertex = vertices[vertex_id];

            for (Edge edge: vertex.edges) {
                long long new_distance = vertex.distance + edge.weight;
                Vertex& adjacent_vertex = vertices[edge.vertex];

                if (new_distance < adjacent_vertex.distance) {
                    pq.push(adjacent_vertex);
                    adjacent_vertex.distance = new_distance;
                }
            }
        }
//        cout << endl;
    }

    void print_distances() {
        for (long long query: quires) {
            long long distance = vertices[query].distance;
            if (distance == LLONG_MAX) {
                cout << "Impossible" << endl;
            } else {
                cout << distance << endl;
            }
        }
    }
};

void run_dijkstra_multiple_graphs(vector<Graph>& graphs) {
    for (Graph& graph: graphs) {
        graph.dijkstra();
    }
}

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

vector<Graph> get_graphs_from_input(bool print=false) {
    vector<Graph> graphs;

    while (true) {
        long long vertices_amount, edges, quires_amount, starting_vertex;
        cin >> vertices_amount >> edges >> quires_amount >> starting_vertex;
        if (vertices_amount == 0 and edges == 0 and quires_amount == 0 and starting_vertex == 0) {
            break;
        }
        Graph graph = Graph(vertices_amount, quires_amount, starting_vertex);
        graph.add_edges_and_quires_from_input(edges, quires_amount, print);
        graphs.push_back(graph);
    }

    return graphs;
}

int main() {
    vector<Graph> graphs = get_graphs_from_input(false);
    run_dijkstra_multiple_graphs(graphs);
    print_distances_multiple_graphs(graphs);

    return 0;
}
