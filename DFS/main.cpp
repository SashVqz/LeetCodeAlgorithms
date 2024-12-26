#include <iostream>
#include <vector>
using namespace std;

void dfs(const vector<vector<int>>& graph, int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    
    for (int i = 0; i < graph.size(); i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(graph, i, visited);
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> graph(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    vector<bool> visited(N, false);
    dfs(graph, 0, visited);
    cout << endl;
    return 0;
}