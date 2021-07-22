//
// Created by Zeeshan Shaikh on 6/20/21.
//

// This program conserves the order of the elements in the array

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

// Function for right rotation
void rightRotate(int arr[], int lenArr, int outOfPlace, int index){
    int temp = arr[index];

    // Iterate over the array
    for (int i = index; i > outOfPlace; i--) {
        arr[i] = arr[i-1];
    }
    // Adding the last element
    arr[outOfPlace] = temp;
}

void rearrangeArray(int arr[], int lenArr){
    int outOfPlace = -1;

    // Iterate over the array
    for (int i = 0; i < lenArr; i++) {

        // If the element is out of place
        if (outOfPlace >= 0){
            if (((arr[i] >= 0) && arr[outOfPlace] < 0) || ((arr[i] < 0) && (arr[outOfPlace] >= 0))){

                // Rotate the array
                rightRotate(arr, lenArr, outOfPlace, i);

                if((i - outOfPlace) >= 0){
                    outOfPlace += 2;
                }
                else{
                    outOfPlace = -1;
                }
            }
        }

        // Check if the element is out of place
        if (outOfPlace == -1){
            if(((arr[i] >= 0) && (i%2 == 0)) || ((arr[i] < 0) && i%2 == 1)){
                outOfPlace = i;
            }
        }
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
