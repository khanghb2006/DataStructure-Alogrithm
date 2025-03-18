#include<iostream>
#include<stdio.h>

using namespace std;

struct Stack {

    struct Node {
        int data;
        Node* next;
    };

    Node* head;
    int sz;

    Stack () {
        head = nullptr;
        sz = 0;
    }

    void Push(int x) {
        Node* newNode = new Node{x , head};
        head = newNode;
        sz++;
    }

    int Top() {
        return head->data;
    }

    void Pop() {
        if(!head) return;
        Node* tmp = head;
        head = head->next;
        delete tmp;
        sz--;
    }
};

