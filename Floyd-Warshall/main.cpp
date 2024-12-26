#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void floydWarshall(vector<vector<int>>& graph) {
    int N = graph.size();
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX && graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> graph(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INT_MAX;
            }
        }
    }

    floydWarshall(graph);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}