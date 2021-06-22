//
// Created by Zeeshan Shaikh on 6/22/21.
//

#include <iostream>

using namespace std;

void printArray(int arr[], int lenArr){
    // This function is used to print an array
    cout << "The elements in the array are: ";
    for (int i = 0; i < lenArr; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverseArray(int arr[], int start, int end, int lenArr){
    // This functions reverses the array that is passed to it
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateArray(int arr[], int lenArr, int rotations){
    // This function rotates the array by the required number of rotations
    reverseArray(arr, 0, rotations-1, lenArr);
    reverseArray(arr, rotations, lenArr-1, lenArr);
    reverseArray(arr, 0, lenArr-1, lenArr);
}

int main(){
    // Defining the array here
    int defaultArray[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int lenArr = sizeof(defaultArray)/sizeof(defaultArray[0]);

    // Defining a variable to hold the number of rotations
    int rotations;

    // Take in input from the user for the number of elements to rotate
    cout << "Enter the number of rotations" << " (less than " << lenArr << "): ";
    cin >> rotations;

    // Sanity check of current array
    cout << "The array before rotation is: " << endl;
    printArray(defaultArray, lenArr);
    cout << endl;

    // Sanity check for array rotation
    cout << "The array after rotation is: " << endl;
    rotateArray(defaultArray, lenArr, rotations);
    printArray(defaultArray, lenArr);
}