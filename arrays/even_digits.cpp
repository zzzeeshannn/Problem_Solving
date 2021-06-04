//
// Created by zee on 6/4/21.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int findNumbers(vector<int>& nums)
{
    int count = 0;
    int temp_count = 0;
    for(auto &val: nums){
        while(val > 0){
            val /= 10;
            temp_count++;
        }
        if(temp_count % 2 == 0){
            count++;
        }
        temp_count = 0;
    }
    return count;
}

int main(){
    vector<int> defaultArray;
    defaultArray = {123, 45, 678, 91011, 1213, 78};
    int output1 = findNumbers(defaultArray);
    cout << "Total number of elements with double digits: " << output1 << endl;
}