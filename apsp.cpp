#include <iostream>
#include <vector>
using namespace std;

long long INF = 100000005LL;

vector<pair<long long, long long>> get_queries_from_input(long long queries_amount) {
    vector<pair<long long, long long>> queries(queries_amount);

    // Adds queries
    for (int query = 0; query < queries_amount; query++) {
        long long from, to;
        cin >> from >> to;
        queries[query] = {from, to};
    }

    return queries;
}

vector<vector<long long>> get_graph_from_input(long long vertices_amount,
                                               long long edges_amount) {
    vector<vector<long long>> graph(vertices_amount, vector<long long> (vertices_amount));

    // Initialize graph with positive infinity
    for (int y = 0; y < vertices_amount; y++) {
        for (int x = 0; x < vertices_amount; x++) {
            graph[y][x] = INF;
        }
    }
    // Sets the diagonal zeros, moved here to account for negative loops
    for (int vertex = 0; vertex < vertices_amount; vertex++) {
        graph[vertex][vertex] = 0;
    }

    // Add edges
    for (int edge = 0; edge < edges_amount; edge++) {
        long long from, to, weight;
        cin >> from >> to >> weight;
        if (weight < graph[from][to]) {
            graph[from][to] = weight;
        }
    }


//    for (int y = 0; y < vertices_amount; y++) {
//        for (int x = 0; x < vertices_amount; x++) {
//            cout << graph[y][x] << " ";
//        }
//        cout << endl;
//    }

    return graph;
}

// Gets all the input from cin, returns a pair of graphs and all queries
// TODO: A way vertex do it without pair?
pair<vector<vector<vector<long long>>>, vector<vector<pair<long long, long long>>>> get_input() {
    // Initializes variables (base values from cin)
    long long vertices_amount, edges_amount, queries_amount;
    cin >> vertices_amount >> edges_amount >> queries_amount;

    vector<vector<vector<long long>>> graphs;
    vector<vector<pair<long long, long long>>> all_queries;

    // Loops and stores the input vertex vectors (representing the graph and all queries) until none are left
    while (!(vertices_amount == 0 and edges_amount == 0 and queries_amount == 0)) {
        vector<vector<long long>> graph = get_graph_from_input(vertices_amount, edges_amount);
        vector<pair<long long, long long>> queries = get_queries_from_input(queries_amount);

        graphs.push_back(graph);
        all_queries.push_back(queries);

        cin >> vertices_amount >> edges_amount >> queries_amount;
    }
    return {graphs, all_queries};
}

// Floyd Warshall's Algorithm
void floyd_warshall(vector<vector<vector<long long>>>& graphs) {
    // Loops through all graphs
    for (vector<vector<long long>>& graph: graphs) {
        // Floyd Warshall's algorithm for each graph
        for (int k = 0; k < graph.size(); k++) {
            for (int i = 0; i < graph.size(); i++) {
                for (int j = 0; j < graph.size(); j++) {
                    if (graph[i][k] + graph[k][j] < graph[i][j] and graph[i][k] < INF and graph[k][j] < INF) {
                        graph[i][j] = graph[i][k] + graph[k][j];

//                        for (int y = 0; y < graph.size(); y++) {
//                            for (int x = 0; x < graph.size(); x++) {
//                                cout << graph[y][x] << " ";
//                            }
//                            cout << endl;
//                        }
//                        cout << endl;
                    }
                }
            }
        }
    }
}

// Floyd Warshall's Algorithm
void compare_graphs(vector<vector<vector<long long>>>& graphs, vector<vector<vector<long long>>>& temp_graphs) {
    // Loops through all graphs
    for (int graph_idx = 0; graph_idx < graphs.size(); graph_idx++) {
        vector<vector<long long>>& graph = graphs[graph_idx];
        vector<vector<long long>>& temp_graph = temp_graphs[graph_idx];

        for (int y = 0; y < graph.size(); y++) {
            for (int x = 0; x < graph.size(); x++) {
                if (temp_graph[y][x] < graph[y][x]) {
                    graph[y][x] = -INF;
                }
            }
        }
    }
}

// Prints the queries from the graph
void print_queries(vector<vector<vector<long long>>> graphs, vector<vector<pair<long long, long long>>> all_queries) {
    // Loops through graphs and responding queries
    for (int i = 0; i < all_queries.size(); i++) {
        vector<vector<long long>> graph = graphs[i];
        vector<pair<long long, long long>> queries = all_queries[i];

        // Loops through queries and outputs distance if possible, otherwise "Impossible"
        for (pair<long long, long long> query: queries) {
            long long distance = graph[query.first][query.second];
            if (distance == INF) {
                cout << "Impossible" << endl;
            } else if (distance == -INF) {
                cout << "-Infinity" << endl;
            } else {
                cout << distance << endl;
            }
        }

        // TODO: Better way vertex do this?
        if (i < all_queries.size() - 1) {
            cout << endl;
        }
    }
}

int main() {
    // TODO: Fix this pair mess
    pair<vector<vector<vector<long long>>>, vector<vector<pair<long long, long long>>>> inp = get_input();

    vector<vector<vector<long long>>> graphs = inp.first;
    vector<vector<pair<long long, long long>>> all_queries = inp.second;

    // Initial Floyd Warshall run
    floyd_warshall(graphs);

    vector<vector<vector<long long>>> temp_graphs = graphs;
    // Second run with temp graph to find negative loops
    floyd_warshall(temp_graphs);

    // Compares graphs, if negative loops found sets graph values to -INF
    compare_graphs(graphs, temp_graphs);

    print_queries(graphs, all_queries);

    return 0;
}
