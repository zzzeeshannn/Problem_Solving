//
// Created by Zeeshan Shaikh on 6/28/21.
//

#include <iostream>
#include <queue>

using namespace std;

class Stack{
    // We use two queues to push values into the representing stack
    // Declare the two queues
    queue <int> q1, q2;
    // Variable to hold the size of the stack
    int size;
public:
    // Constructor
    Stack(){
        size = 0;
    }
    // Push operation - more expensive
    void push(int value){
        size ++;
        // Push to q2
        q2.push(value);

        // Add values of q1 to q2
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        // Interchange the names of q1 and q2
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    // Pop operation
    void pop(){
        if (q1.empty()){
            return;
        }
        q1.pop();
        size --;
    }
    // Top operation
    int top(){
        if(q1.empty()){
            return -1;
        }
        return q1.front();
    }
    // Size of the stack
    int sizeOf(){
        return  size;
    }
};

int main(){
    // Declare the stack
    Stack S;
    // Test Push
    S.push(10);
    S.push(20);
    S.push(30);
    cout << "The size of the stack is: " << S.sizeOf() << endl;
    cout << "The element on top is: " << S.top() << endl;
    // Test pop
    S.pop();
    cout << "The element on top is: " << S.top() << endl;
    return 0;
}