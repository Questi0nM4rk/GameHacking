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
    uptr<Node> head = nullptr;
    uptr<Node> tail = nullptr;
    int size = 0;

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    Node* addNodeStart(const int &val);

    Node* addNodeEnd(const int &val);

    Node* insertNode(const int &pos, const int &val);

    Node* getNodeIndex(const int &val);

    Node* getNodeVal(const int &pos);

    uptr<Node> popNode();

    bool remNode(const int &val);

    bool clearList();

    int getSize();

    void printList();
};