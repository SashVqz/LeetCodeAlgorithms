#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = { -1, 1, 0, 0 }; // Up, Down, Left, Right
const int dy[] = { 0, 0, -1, 1 }; // Up, Down, Left, Right

bool isSafe(const vector<vector<int>>& maze, int x, int y, const vector<vector<bool>>& visited, int N) {
    return (x >= 0 && y >= 0 && x < N && y < N && maze[x][y] == 1 && !visited[x][y]);
}

bool solveMaze(vector<vector<int>>& maze, vector<vector<int>>& solution, vector<vector<bool>>& visited, int x, int y, int N) {
    if (x == N - 1 && y == N - 1) {
        solution[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y, visited, N)) {
        visited[x][y] = true;
        solution[x][y] = 1;

        for (int dir = 0; dir < 4; dir++) {
            int newX = x + dx[dir];
            int newY = y + dy[dir];

            if (solveMaze(maze, solution, visited, newX, newY, N)) {
                return true;
            }
        }

        solution[x][y] = 0;
        visited[x][y] = false;
        return false;
    }
    return false;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> maze(N, vector<int>(N));
    vector<vector<int>> solution(N, vector<int>(N, 0)); 
    vector<vector<bool>> visited(N, vector<bool>(N, false)); 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
        }
    }

    if (solveMaze(maze, solution, visited, 0, 0, N)) {
        cout << "Solution found:" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << (solution[i][j] ? "1 " : "0 ");
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}