#include "LinkedList.hpp"

ListNode::ListNode(int x) : val(x), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::insert(int val) {
    ListNode* node = new ListNode(val);
    node->next = head;
    head = node;
}

void LinkedList::print() const {
    for (ListNode* curr = head; curr != nullptr; curr = curr->next) {
        std::cout << curr->val << " ";
    }
    std::cout << "\n";
}

void LinkedList::reverse() {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    head = prev;
}

bool LinkedList::hasCycle() const {
    if (!head) return false;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

DListNode::DListNode(int x) : val(x), prev(nullptr), next(nullptr) {}

DoublyLinkedList::DoublyLinkedList() : head(nullptr) {}

void DoublyLinkedList::insert(int val) {
    DListNode* node = new DListNode(val);
    if (head) {
        head->prev = node;
    }
    node->next = head;
    head = node;
}

void DoublyLinkedList::print() const {
    for (DListNode* curr = head; curr != nullptr; curr = curr->next) {
        std::cout << curr->val << " ";
    }
    std::cout << "\n";
}
