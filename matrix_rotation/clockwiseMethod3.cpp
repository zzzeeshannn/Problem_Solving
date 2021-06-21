//
// Created by Zeeshan Shaikh on 6/20/21.
//

// In this method, we will rotate the matrix by
// rotating the elements of the matrix first along the secondary diagonal
// and then, rotating the resultant matrix along the central axis of rows

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
    // Defining a temp variable
    int temp;

    // Rotating along the primary diagonal
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[N - j - 1][N - i - 1];
            matrix[N - j - 1][N - i - 1] = temp;
        }
    }

    // Sanity Check
    cout << "The matrix after rotating along the primary diagonal looks like: " << endl;
    printMatrix(matrix);

    // Rotating along the middle axis
    for (int i = 0; i < N/2; i++) {
        for (int j = 0; j < N; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[N - i - 1][j];
            matrix[N - i - 1][j] = temp;
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