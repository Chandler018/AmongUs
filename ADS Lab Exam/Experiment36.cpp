#include <iostream>
using namespace std;

int board[10][10];

int n;

// Check safe position
bool isSafe(int row, int col) {

    // Check column
    for(int i = 0; i < row; i++) {

        if(board[i][col] == 1)
            return false;
    }

    // Left diagonal
    for(int i = row, j = col;
        i >= 0 && j >= 0;
        i--, j--) {

        if(board[i][j] == 1)
            return false;
    }

    // Right diagonal
    for(int i = row, j = col;
        i >= 0 && j < n;
        i--, j++) {

        if(board[i][j] == 1)
            return false;
    }

    return true;
}

// Solve N-Queen
bool solve(int row) {

    // All queens placed
    if(row == n)
        return true;

    // Try all columns
    for(int col = 0; col < n; col++) {

        if(isSafe(row, col)) {

            board[row][col] = 1;

            if(solve(row + 1))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {

    cout << "Enter number of queens: ";
    cin >> n;

    if(solve(0)) {

        cout << "\nSolution:\n";

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                cout << board[i][j]
                     << " ";
            }

            cout << endl;
        }
    }

    else {

        cout << "\nNo Solution Exists";
    }

    return 0;
}