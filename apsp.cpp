#include <iostream>
using namespace std;
long long INFP = 100000005LL;
long long INFN = -100000005LL;

void floyd_warshall() {
    long long vertices_amount, edges_amount, quires_amount;
    cin >> vertices_amount >> edges_amount >> quires_amount;

    while (vertices_amount != 0 and edges_amount != 0 and quires_amount != 0) {
        long long graph [vertices_amount][vertices_amount];

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

        cout << endl;
    }

}

int main() {
    floyd_warshall();

    return 1;
}
