//
// Created by zee on 6/7/21.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Naive Method
int trap(vector<int>& height) {
    int ans = 0;
    int len = height.size();
    for(int i = 0; i<len; i++){
        int left_max = 0;
        int right_max = 0;
        for(int j = i; j>=0; j--){
            left_max = max(left_max, height[j]);
        }
        for(int j = i; j<len; j++){
            right_max = max(right_max, height[j]);
        }
        ans += (min(left_max, right_max) - height[i]);
    }
    return ans;
}

// Fastest answer on LeetCode using dynamic programming
int trap_dp(vector<int>& height) {
    int ans = 0;
    int len = height.size();

    if(len == 0){
        return 0;
    }

    int left_max[len];
    int right_max[len];
    // Initializing the max values to default values
    left_max[0] = height[0];
    right_max[len-1] = height[len-1];

    for(int i = 1; i < len; i++){
        left_max[i] = max(height[i], left_max[i-1]);
    }
    for(int i = len-2; i>=0; i--){
        right_max[i] = max(height[i], right_max[i+1]);
    }

    for(int i=0; i<len; i++){
        ans += min(left_max[i], right_max[i]) - height[i];
    }
    return ans;
}

// Finding the answer using stacks
int trap_stack(vector<int>& height) {
    int current = 0;
    int ans = 0;

    stack<int> st;
    while(current < height.size()){
        while(!st.empty() && height[current]>height[st.top()]){
            int top = st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            else{
                int distance = current - st.top() - 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                ans += bounded_height*distance;
            }
        }
        st.push(current++);
    }
    return ans;
}

// Using two pointer method
int trap_twoPointer(vector<int>& height)
{
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
        }
        else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;
}

int main(){
    // Defining the array that stores the height of the elements
    vector<int> height;
    height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // Output
    int totalWater = trap(height);
    cout << "The total amount of water that can be saved is: " << totalWater << " (NAIVE METHOD)" << endl;
    // Output
    int totalWater2 = trap_dp(height);
    cout << "The total amount of water that can be saved is: " << totalWater2 << " (DYNAMIC PROGRAMMING METHOD)" << endl;
    // Output
    int totalWater3 = trap_stack(height);
    cout << "The total amount of water that can be saved is: " << totalWater3 << " (STACK METHOD)" << endl;
    // Output
    int totalWater4 = trap_twoPointer(height);
    cout << "The total amount of water that can be saved is: " << totalWater4 << " (TWO POINTER METHOD)" << endl;
}

