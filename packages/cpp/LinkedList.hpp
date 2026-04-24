#pragma once
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x);
};

class LinkedList {
    ListNode* head;
public:
    LinkedList();
    void insert(int val);
    void print() const;
};

struct DListNode {
    int val;
    DListNode* prev;
    DListNode* next;
    DListNode(int x);
};

class DoublyLinkedList {
    DListNode* head;
public:
    DoublyLinkedList();
    void insert(int val);
    void print() const;
};
