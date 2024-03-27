#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    int i, j;

    // Проверяем, есть ли ферзь в этом же столбце выше по вертикали
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Проверяем, есть ли ферзь в верхнем левом диагональном направлении
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Проверяем, есть ли ферзь в верхнем правом диагональном направлении
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row, int N) {
    if (row >= N)
        return true;

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;
            if (solveNQueens(board, row + 1, N))
                return true;
            board[row][col] = 0; // Возврат к предыдущему шагу
        }
    }

    return false;
}

int main() {
    int N;
    cout << "Введите размер доски N x N: ";
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueens(board, 0, N)) {
        cout << "Решение найдено:" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
    else {
        cout << "Решение не найдено" << endl;
    }

    return 0;
}
