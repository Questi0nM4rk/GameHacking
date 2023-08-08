#pragma once

//includes

#include "../../basic.h"

//aliases
template <typename U>
using uptr = std::unique_ptr<U>;

// the list

struct Node {
    int data;
    std::unique_ptr<Node> next;

    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    std::unique_ptr<Node> head = nullptr;

public:
    SinglyLinkedList() : head(nullptr) {}

    Node* addNode(const int &val);

    bool remNode(const int &val);

    Node* insertNode(const int &pos, const int &val);

    void printList();
};