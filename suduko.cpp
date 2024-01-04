#include <iostream>
using namespace std;

#define N 9

void print(int arr[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

int isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num || grid[x][col] == num)
            return 0;

    int startRow = row - row % 3, startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return 0;

    return 1;
}

int solveSudoku(int grid[N][N]) {
    int row, col;

    // Find the first unassigned location
    int found = 0;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
 found = 1;
                break;
            }
        }
        if (found)
            break;
    }

    // If no unassigned location is found, the Sudoku is solved
    if (!found)
        return 1;

    // Try placing digits 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            // Recursively solve the rest of the Sudoku
            if (solveSudoku(grid))
                return 1;

            // If placing num doesn't lead to a solution, backtrack
            grid[row][col] = 0;
        }
    }

    // No solution found for this combination
    return 0;
}
int main() {
    int grid[N][N];
    cout<<"Enter the suduko grid numbers and zero in blank spaces"<<endl;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>grid[i][j];
        }
    }
       cout<<endl;
    if (solveSudoku(grid)){
        cout<<"solved suduko"<<endl;
        print(grid);}
    else{
        cout << "No solution exists";}

     return 0;
}