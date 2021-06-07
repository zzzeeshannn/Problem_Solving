//
// Created by zee on 6/4/21.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void print_array(int defaultArray[], int len){
    std::cout << "The array is: ";
    for (int i = 0; i < len; i++) {
        std::cout << defaultArray[i] << " ";
    }
    std::cout << std::endl;
}

int sortedSquares(int arr[], int arrayLength){
    int finalArray[arrayLength];
    int left = 0;
    int right = arrayLength - 1;

    while (left <= right){
        int left_value = abs(arr[left]);
        int right_value = abs(arr[right]);

        if (left_value > right_value){
            finalArray[right - left] = pow(left_value, 2);
            left++;
        }
        else{
            finalArray[right - left] = pow(right_value, 2);
            right--;
        }
    }

    for (int i = 0; i < arrayLength; i++) {
        arr[i] = finalArray[i];
    }
}

int main(){
    int defaultArray[] = {-7, -2, -1, 1, 2, 4, 7};
    int len = sizeof(defaultArray)/sizeof(defaultArray[0]);
    cout << "Length is: " << len << endl;
    sortedSquares(defaultArray, len);
    print_array(defaultArray, len);
}