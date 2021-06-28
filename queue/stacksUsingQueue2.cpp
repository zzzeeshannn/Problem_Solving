//
// Created by Zeeshan Shaikh on 6/28/21.
//

#include <iostream>
#include <queue>

using namespace std;

class Stack{
    // Declare the two queues
    queue<int> q1, q2;
    // Declare a variable to hold the size of the stack
    int size;
public:
    // Constructor
    Stack(){
        size = 0;
    }
    // Push operation
    void push(int value){
        // Push the value into q1
        size++;
        q1.push(value);
    }
    // Pop operation
    void pop(){
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        // Pop the remaining element in q1
        q1.pop();
        size--;
        // Interchange the queues
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    // Top operation
    int top(){
        if (q1.empty()){
            return -1;
        }
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        int output = q1.front();
        q2.push(output);
        q1.pop();

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        return output;
    }
    // Size operation
    int sizeOf(){
        return size;
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