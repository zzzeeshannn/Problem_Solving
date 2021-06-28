//
// Created by Zeeshan Shaikh on 6/28/21.
//

#include <iostream>
#include <queue>

using namespace std;

void printBinary(int num){
    // This function prints binary numbers from decimal values 1 to num
    queue<string> binary;

    // Adding the first binary number
    binary.push("1");
    while (num--){
        string output = binary.front();
        binary.pop();
        cout << output << " ";

        string temp = output;
        binary.push(temp.append("0"));
        binary.push(output.append("1"));
    }
}

int main(){
    // Declaring the number of binary number
    int num = 10;
    printBinary(num);
}