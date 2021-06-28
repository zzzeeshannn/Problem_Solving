//
// Created by Zeeshan Shaikh on 6/28/21.
//

#include <iostream>

using namespace std;

struct Node{
    // Node defining the basic structure of the linked list
    int data;
    Node *next;
};

Node * result = NULL;

Node *newNode(int value){
    // This function adds a new node to the linked list
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;
    return temp;
}

Node * sortedMerge(Node *temp, Node *temp2){
    cout << "Entered sort" << endl;

    // Base cases
    if(temp == NULL){
        return temp2;
    }
    else if(temp2 == NULL){
        return temp;
    }

    if(temp->data <= temp2->data){
        result = temp;
        result->next = sortedMerge(temp->next, temp2);
    }
    else{
        result = temp2;
        result->next = sortedMerge(temp, temp2->next);
    }

    cout << "Exiting sort" << endl;
    return result;
}
Node * mergeLinkedLists(Node *arr[3], int k){
    // This function recursively merges linked lists
    cout << "Entered main" << endl;
    while (k != 0){
        int i = 0, j = k;
        while(i < j){
            arr[i] = sortedMerge(arr[i], arr[j]);
            i++;
            j--;
            if (i >= j){
                k = j;
            }
        }
    }
    cout << "Finished main" << endl;
    return arr[0];
}

void printList(Node *node){
    // This function is used to print list
    cout << "The list is: ";
    while(node != NULL){
        cout << node->data << " ";
    }
    cout << endl;
}

int main(){
    // Defining an array of sorted linked lists here
    // Total number of linked lists
    int k = 3;

    Node *arr[k];

    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);

    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);

    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);

    Node* output = mergeLinkedLists(arr, k-1);

    printList(output);
}