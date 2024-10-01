#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check if placing a queen is valid
bool isValid(vector<string>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;
    return true;
}

// Function to solve the N-Queens problem
void solve(vector<vector<string>>& result, vector<string>& board, int row, int n) {
    if (row == n) {
        result.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isValid(board, row, col, n)) {
            board[row][col] = 'Q';
            solve(result, board, row + 1, n);
            board[row][col] = '.';
        }
    }
}

// Function to initiate the N-Queens solution
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    solve(result, board, 0, n);
    return result;
}

// Function to print the solutions
void printSolutions(const vector<vector<string>>& solutions) {
    for (const auto& solution : solutions) {
        for (const auto& row : solution) {
            cout << row << endl;
        }
        cout << endl; // Print a newline for better separation of solutions
    }
}

int main() {
    int n;
    cout << "Enter the value of n for the N-Queens problem: ";
    cin >> n;

    // Get the solutions
    vector<vector<string>> solutions = solveNQueens(n);

    // Print the solutions
    cout << "Number of solutions: " << solutions.size() << endl;
    printSolutions(solutions);

    return 0;
}
