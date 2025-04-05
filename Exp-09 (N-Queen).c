/*          Name : Antuley Aman Siraj.
            Roll No. : 23CO25
            Branch : SE-CO
            Batch : 01

            Aim : Implement algorithm to solve n-Queen problem.

            Theory : The N-Queen Problem is a classic backtracking problem where the goal is to place N queens on an N×N chessboard such that no two queens threaten each other. That means no two queens share the same row, column, or diagonal.

            This problem is often solved using backtracking, a form of recursion that tries to build a solution incrementally and backtracks as soon as it determines that a path won’t lead to a valid solution.

            Algorithm : 
            Start from the first row (row = 0).
            Try placing a queen in each column of the current row.
            For each placement, check if it's safe (no queens in the same column or diagonal).
            If safe, place the queen and move to the next row.
            If all queens are placed, print/store the solution.
            If no valid column is found, backtrack to the previous row.

        
*/ 


#include <stdio.h>
#include <stdlib.h>

int board[20], count;

int isSafe(int row, int col) {
    int i;
    for (i = 1; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void printBoard(int n) {
    int i, j;
    printf("\nSolution %d:\n", ++count);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

void solve(int row, int n) {
    int col;
    for (col = 1; col <= n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            if (row == n)
                printBoard(n);
            else
                solve(row + 1, n);
        }
    }
}

int main() {
    int n;
    printf("Enter number of queens: ");
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Invalid input. Enter a number between 1 and 20.\n");
        return 0;
    }

    count = 0;
    solve(1, n);

    if (count == 0)
        printf("No solutions found.\n");

    return 0;
}

/*
Output : 
Enter number of queens: 5

Solution 1:
Q . . . . 
. . Q . . 
. . . . Q 
. Q . . . 
. . . Q . 

Solution 2:
Q . . . . 
. . . Q . 
. Q . . . 
. . . . Q 
. . Q . . 

Solution 3:
. Q . . .
. . . Q .
Q . . . .
. . Q . .
. . . . Q

Solution 4:
. Q . . .
. . . . Q
. . Q . .
Q . . . .
. . . Q .

Solution 5:
. . Q . .
Q . . . .
. . . Q .
. Q . . . 
. . . . Q

Solution 6:
. . Q . .
. . . . Q
. Q . . .
. . . Q .
Q . . . .

Solution 7:
. . . Q .
Q . . . .
. . Q . .
. . . . Q
. Q . . .

Solution 8:
. . . Q .
. Q . . .
. . . . Q
. . Q . .
Q . . . .

Solution 9:
. . . . Q
. Q . . .
. . . Q .
Q . . . .
. . Q . .

Solution 10:
. . . . Q
. . Q . .
Q . . . .
. . . Q .
. Q . . .


Time-Complexity :

Best Case: O(N)
Worst Case: O(N!)
Average Case: O(N!)
*/

/*
Conclusion : The N-Queen problem is a fundamental example of applying backtracking to solve constraint satisfaction problems. It helps develop skills in recursion, logical problem solving, and optimization. Though the naive approach is inefficient for large N, it demonstrates how smart pruning (like checking column and diagonal safety) can significantly reduce the search space.
*/