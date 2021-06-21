//
// Created by Zeeshan Shaikh on 6/20/21.
//

// In this method, we will rotate the matrix by
// rotating the elements of the matrix in an orderly fashion in antiClockwise direction
// This is also called inplace rotation and requires only 1 temporary variable

#include <iostream>

using namespace std;

// Defining the dimension of the square matrix here
#define N 3

// Function to print the matrix
void printMatrix(int matrix[N][N]){

    cout << "The elements of the matrix are: " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Matrix rotation function
void rotateMatrix(int matrix[N][N]){
    // Defining a temp variable here
    int temp;

    // Traversing through the matrix and rotating
    for (int i = 0; i < N/2; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][N - i - 1];
            matrix[j][N - i - 1] = matrix[N - i - 1][N - j - 1];
            matrix[N - i - 1][N - j - 1] = matrix[N - j - 1][i];
            matrix[N - j - 1][i] = temp;
        }
    }
}

// Main function
int main(){
    // Defining the matrix here
    int matrix[N][N] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    // Sanity check
    cout << "The matrix before rotation is: " << endl;
    printMatrix(matrix);

    rotateMatrix(matrix);

    // Sanity check
    cout << "The matrix after rotation is: " << endl;
    printMatrix(matrix);
}