#include<iostream>
#include<stdio.h>

using namespace std;

struct Queue {
    struct Node {
        int data;
        Node* next;
    };

    Node *head , *tail;
    int sz;

    Queue() {
        head = nullptr;
        tail = nullptr;
        sz = 0;
    }

    void enqueue(int x) {
        Node *newNode = new Node{x , nullptr};
        if(head == nullptr) {
            head = tail = newNode;
            sz++;
            return;
        }
        tail -> next = newNode;
        tail = newNode;
        sz++;
    }

    void dequeue() {
        if(!head) return;
        Node *tmp = head;
        head = head->next;
        delete tmp;
        sz--;
    }

    int front() {
        return head->data;
    }
};