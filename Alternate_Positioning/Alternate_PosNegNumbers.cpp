//
// Created by Zeeshan Shaikh on 6/19/21.
//

// This program does not conserve the order of the elements of the array

#include <iostream>

using namespace std;

//  Function to print an array
void printArray(int arr[], int lenArr){
    cout << "The array is: ";
    for (int i = 0; i < lenArr; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void rearrangeArray(int arr[], int lenArr){
    // Defining the pivot here
    // In this case since we need to distinguish between positive and negative numbers
    // We set the pivot to 0
    int pivot = 0;

    // Initialize an iterator for swap
    int i = -1;

    // Loop over array and rearrange elements based on if they are greater than or less than 0
    for (int j = 0; j < lenArr - 1; j++) {
        if (arr[j] < pivot){
            // Increment iterator
            i++;
            // Swap
            swap(arr[j], arr[i]);
        }
    }
    // After the last loop, all negative numbers are the start of the array
    // And all positive numbers are after them

    // Define the indices for positive and negative number
    int positive_index = i+1;
    int negative_index = 0;

    // Rearrange positive and negative numbers to be represented in an alternate fashion
    while (positive_index < lenArr && negative_index < positive_index && arr[negative_index] < 0){
        swap(arr[positive_index], arr[negative_index]);
        positive_index++;
        negative_index += 2;
    }
}

int main(){
    // Defining the array here
    int arr[] = {-1, 2, 3, -2, 5, -8, 9, -4, 6};

    // Getting the length of the array here
    int lenArr = sizeof(arr)/ sizeof(arr[0]);

    // Sanity check
    cout << "The length of the array is: " << lenArr << endl;
    cout << "The array before rearranging is: ";
    printArray(arr, lenArr);

    // Calling the function here
    rearrangeArray(arr, lenArr);

    // Sanity check
    cout << "The array after rearranging is: ";
    printArray(arr, lenArr);
}