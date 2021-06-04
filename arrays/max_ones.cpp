//
// Created by zee on 6/4/21.
//

#include <iostream>
#include <vector>

using namespace std;
// This was the fastest method at the time
// Another possible approach is the sliding window approach but it is comparatively slower
// Alternatively we can convert to string and split by 0 as well
int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0;
    int output = 0;
    for(auto &val: nums){
        if(val){
            count++;
        }
        else{
            output = max(output, count);
            count = 0;
        }
    }
    output = max(output, count);
    return output;
}

int main(){
    // Defining the array here
    std::vector<int> defaultArray;
    defaultArray = {1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1};

    int output = findMaxConsecutiveOnes(defaultArray);

    std::cout << "The maximum number of ones in a row are: " << output << std::endl;
}