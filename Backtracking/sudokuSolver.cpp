#include <iostream>
using namespace std;

const int N = 9;

// Function to check if a value can be placed in the given cell
bool isSafe(int board[N][N], int row, int col, int num) {
    // Check row and column
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }

    // Check 3x3 grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num)
                return false;
        }
    }

    return true;
}

// Function to find an empty cell (with value 0) in the board
bool findEmptyCell(int board[N][N], int& row, int& col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board[row][col] == 0)
                return true;
        }
    }
    return false;
}

// Function to solve the Sudoku board using backtracking
bool solveSudoku(int board[N][N]) {
    int row, col;
    if (!findEmptyCell(board, row, col))
        return true; // All cells are filled

    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board))
                return true;
            board[row][col] = 0; // Backtrack
        }
    }

    return false;
}

// Function to print the Sudoku board
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int board[N][N];

    cout << "Enter the Sudoku board (9x9) with 0 for empty cells:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    if (solveSudoku(board)) {
        cout << "Sudoku board can be solved. The solution is:" << endl;
        printBoard(board);
    } else {
        cout << "Sudoku board cannot be solved." << endl;
    }

    return 0;
}
