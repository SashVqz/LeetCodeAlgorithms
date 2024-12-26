#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(const vector<vector<int>>& graph, int source) {
    int N = graph.size();
    vector<int> dist(N, INT_MAX);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < N; v++) {
            if (graph[u][v] != 0 && dist[v] > dist[u] + graph[u][v]) {
                dist[v] = dist[u] + graph[u][v];
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << "Distance from " << source << " to " << i << ": " << dist[i] << endl;
    }
}

int main() {
    int N, source;
    cin >> N >> source;
    vector<vector<int>> graph(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    dijkstra(graph, source);
    return 0;
}