#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<string.h>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node *head;
    Node *tail;
};

void initialize(List &list) {
    list.head = list.tail = nullptr;
}

void traversal_Node(List list) {
    cout << "Traversal Node" << "\n";
    for (Node * ptr = list.head; ptr ; ptr = ptr->next)
        cout << ptr->data << " ";
    cout << "\n";
}

int count_Node(List list) {
    int cntNode = 0;
    for (Node * ptr = list.head ; ptr ; ptr = ptr->next)
        cntNode++;
    return cntNode;
}

void addHead(List &list , int value) {
    Node* newNode = new Node{value , list.head};
    if(!list.head) list.head = list.tail = newNode;
    else list.head = newNode;
}

void addTail(List &list , int value) {
    Node* newNode = new Node{value , nullptr};
    if(!list.head) list.head = list.tail = newNode;
    else list.tail->next = newNode , list.tail = newNode;
}

void deleteHead(List & list) {
    if(!list.head) return;
    if(list.head == list.tail) {
        list.head = list.tail = nullptr;
        return;
    }
    Node* tmp = list.head;
    list.head = list.head->next;
    delete tmp;
}

void deleteTail(List & list) {
    if(list.head == list.tail) {
        list.head = list.tail = nullptr;
        return;
    }
    Node* tmp = list.tail;
    Node* ptr = list.head;
    while(ptr->next != list.tail) ptr = ptr->next;
    list.tail = ptr;
    delete tmp;
}

bool vis[10000007];

List deleteDuplicate(List list) {
    List newList;
    initialize(newList);
    memset(vis , false , sizeof vis);
    for (Node *ptr = list.head ; ptr ; ptr = ptr->next)
        if(!vis[ptr->data]) vis[ptr->data] = true , addTail(newList , ptr->data);
    return newList;
}