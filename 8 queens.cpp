#include <stdio.h>
#include <stdbool.h>
#define N 8  
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
bool isSafe(int board[N][N], int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        if (board[i][col]) {
            return false;
        }
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }
    for (i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}
bool solveNQueens(int board[N][N], int row) {
    if (row >= N) {
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, row, i)) {
            board[row][i] = 1; 

            if (solveNQueens(board, row + 1)) {
                return true;
            }

            board[row][i] = 0;  
        }
    }

    return false;
}

int main() {
    int board[N][N] = {0};

    if (solveNQueens(board, 0)) {
        printBoard(board);
    } else {
        printf("Solution does not exist\n");
    }

    return 0;
}
