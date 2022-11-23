#include <iostream>
#include <vector>

using namespace std;
long long INFP = 100000005LL;
long long INFN = -100000005LL;

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
            graph[y][x] = INFP;
        }
    }

    // Add edges
    for (int edge = 0; edge < edges_amount; edge++) {
        long long from, to, weight;
        cin >> from >> to >> weight;
        graph[from][to] = weight;
    }

    // Sets the diagonal zeros
    // Should be here because the problem sets some graph[i][i] values to not be 0, while expecting 0
    for (int vertex = 0; vertex < vertices_amount; vertex++) {
        graph[vertex][vertex] = 0;
    }

    return graph;
}

pair<vector<vector<vector<long long>>>, vector<vector<pair<long long, long long>>>> get_input() {
    long long vertices_amount, edges_amount, queries_amount;
    cin >> vertices_amount >> edges_amount >> queries_amount;

    vector<vector<vector<long long>>> graphs;
    vector<vector<pair<long long, long long>>> all_queries;


//    long long queries [];
    while (!(vertices_amount == 0 and edges_amount == 0 and queries_amount == 0)) {
        vector<vector<long long>> graph = get_graph_from_input(vertices_amount, edges_amount);
        vector<pair<long long, long long>> queries = get_queries_from_input(queries_amount);

        graphs.push_back(graph);
        all_queries.push_back(queries);

        cin >> vertices_amount >> edges_amount >> queries_amount;
//        cout << endl;
    }
        cout << endl;
    return {graphs, all_queries};
}

int main() {
    // TODO: Fix this mess
    pair<vector<vector<vector<long long>>>, vector<vector<pair<long long, long long>>>> inp = get_input();
//    vector<vector<vector<long long>>> graph = inp.first;
//    vector<vector<pair<long long, long long>>> all_queries = inp.second;


    return 1;
}
