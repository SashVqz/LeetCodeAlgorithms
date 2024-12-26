#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <functional>
using namespace std;

struct Node {
    int x, y;
    double g, h;
    Node(int x, int y, double g, double h) : x(x), y(y), g(g), h(h) {}
    
    double f() const { return g + h; }
};

double heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2); 
}

bool isValid(int x, int y, int N) {
    return x >= 0 && y >= 0 && x < N && y < N;
}

vector<pair<int, int>> AStar(const vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal) {
    int N = grid.size();
    vector<vector<bool>> closed(N, vector<bool>(N, false));
    vector<vector<pair<int, int>>> cameFrom(N, vector<pair<int, int>>(N));
    priority_queue<Node, vector<Node>, greater<Node>> openSet;
    
    openSet.push(Node(start.first, start.second, 0, heuristic(start.first, start.second, goal.first, goal.second)));
    
    while (!openSet.empty()) {
        Node current = openSet.top();
        openSet.pop();
        
        if (current.x == goal.first && current.y == goal.second) {
            vector<pair<int, int>> path;
            while (current.x != start.first || current.y != start.second) {
                path.push_back({current.x, current.y});
                auto [prevX, prevY] = cameFrom[current.x][current.y];
                current = Node(prevX, prevY, 0, 0); 
            }
            path.push_back({start.first, start.second});
            reverse(path.begin(), path.end());
            return path;
        }
        
        if (closed[current.x][current.y]) continue;
        closed[current.x][current.y] = true;
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (auto& dir : directions) {
            int newX = current.x + dir.first;
            int newY = current.y + dir.second;
            if (isValid(newX, newY, N) && grid[newX][newY] == 1 && !closed[newX][newY]) {
                double newG = current.g + 1;
                double newH = heuristic(newX, newY, goal.first, goal.second);
                openSet.push(Node(newX, newY, newG, newH));
                cameFrom[newX][newY] = {current.x, current.y};
            }
        }
    }
    
    return {}; 
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    
    pair<int, int> start, goal;
    cin >> start.first >> start.second >> goal.first >> goal.second;
    
    vector<pair<int, int>> path = AStar(grid, start, goal);
    
    if (path.empty()) {
        cout << "No path found!" << endl;
    } else {
        for (auto& p : path) {
            cout << "(" << p.first << "," << p.second << ") ";
        }
        cout << endl;
    }
    
    return 0;
}