#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(const vector<vector<int>>& graph, int start) {
    int N = graph.size();
    vector<bool> visited(N, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < N; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
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

    bfs(graph, 0);
    cout << endl;
    return 0;
}