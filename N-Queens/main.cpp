#include <iostream>
#include <vector>
using namespace std;

bool isSafe(const vector<vector<int>>& board, int row, int col, int N) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
        if (col - (row - i) >= 0 && board[i][col - (row - i)] == 1) return false;
        if (col + (row - i) < N && board[i][col + (row - i)] == 1) return false;
    }
    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row, int N) {
    if (row >= N) return true;
    
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;
            if (solveNQueens(board, row + 1, N)) return true;
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueens(board, 0, N)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << (board[i][j] ? "Q" : ".") << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists" << endl;
    }
    return 0;
}