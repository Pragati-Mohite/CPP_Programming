#include <iostream>
using namespace std;
const int N=8;
/* Print solution (board contains 0 / 1 values) */
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

/* Check if a queen can be placed on board[row][col] */
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

/* Solve N-Queen problem using backtracking starting from column 'col' */
bool solveNQUtil(int board[N][N], int col)
{
    // If all queens are placed, return true
    if (col >= N)
        return true;

    // Try placing this queen in all rows one by one for column 'col'
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            // Place this queen
            board[i][col] = 1;

            // Recur to place rest of queens
            if (solveNQUtil(board, col + 1) == true)
                return true;

            // If placing queen at board[i][col] doesn't lead to a solution,
            // then remove the queen (backtrack)
            board[i][col] = 0;
        }
    }

    // If queen cannot be placed in any row in this column col then return false
    return false;
}

/* Wrapper that initializes board and calls solver */
bool solveNQ()
{
    int board[N][N] = {0};

    if (solveNQUtil(board, 0) == false) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    printSolution(board);
    return true;
}

/* Main */
int main()
{
    solveNQ();
    return 0;
}