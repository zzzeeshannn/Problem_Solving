//
// Created by Zeeshan Shaikh on 7/21/21.
//
#include <iostream>

using namespace std;
int tempo = 1;

// Function to print arrays
void printArray(char arr[], int flag, int low = 0, int high = 6){
    if(flag == 0){
        cout << "Nuts: || ";
    }
    else{
        cout << "Bolts: || ";
    }
    for (int i = low; i < high; i++) {
        cout << arr[i] << " || ";
    }
    cout << endl;
}

// Partition function here
int partition(char arr[], int low, int high, char pivot){
    // This function will be used to partition the arrays
    int i = low;
    char temp1, temp2;

    for (int j = low; j < high; j++) {
        // Case 1: Array element is less than the pivot character
        if (arr[j] < pivot){
            temp1 = arr[i];
            arr[i] = arr[j];
            arr[j] = temp1;
            i++;
        }
        // Case 2: Array element is equal to the pivot character
        else if (arr[j] == pivot){
            temp1 = arr[j];
            arr[j] = arr[high];
            arr[high] = temp1;
            j--;
        }
    }

    temp2 = arr[i];
    arr[i] = arr[high];
    arr[high] = temp2;

    // Return the partition index
    return i;
}

// Recurrence function here
void matchArrays(char arr[], char arr2[], int low, int high){
    printArray(arr, 0, low, high);
    printArray(arr2, 1, low, high);
    cout << endl;

    // Low iterator should be less than high iterator
    if(low < high){
        // Get pivot/partition index of arr by using the last character of arr2
        int pivot = partition(arr, low, high, arr2[high]);
        cout << "The pivot for iteration " << tempo << " is: " << pivot << " " << arr[pivot] << endl;
        tempo += 1;
        // Use this partition index here to then partition arr2
        partition(arr2, low, high, arr[pivot]);

        // Recursive call here
        // Case 1: low to pivot-1
        matchArrays(arr, arr2, low, pivot-1);
        // Case 2: pivot-1 to high
        matchArrays(arr, arr2, pivot, high);
    }
}

int main(){
    char arr[6] = {'@', '#', '$', '%', '^', '&'};
    char arr2[6] = {'$', '%', '&', '^', '@', '#'};

    for (int i = 0; i < 4; i++) {
        if(arr[i] > arr[i+1]){
            cout << arr[i] << ": " << int(arr[i]) << endl;
            cout << arr[i+1] << ": " << int(arr[i+1]) << endl;
            cout << arr[i] << " is greater than " << arr[i+1] << endl;
            cout << endl;
        }
        else{
            cout << arr[i] << ": " << int(arr[i]) << endl;
            cout << arr[i+1] << ": " << int(arr[i+1]) << endl;
            cout << arr[i+1] << " is greater than " << arr[i] << endl;
            cout << endl;
        }
    }

    // Sanity check
    cout << "The original arrays are: " << endl;
    printArray(arr, 0);
    printArray(arr2, 1);
    cout << endl;

    matchArrays(arr, arr2, 0, 6);

    cout << "The final arrays are: " << endl;
    printArray(arr, 0);
    printArray(arr2, 1);
    cout << endl;

    return 0;
}