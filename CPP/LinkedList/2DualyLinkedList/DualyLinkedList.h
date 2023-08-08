#pragma once

// includes

#include "../../basic.h"

// aliases

template <typename U>
using uptr = std::unique_ptr<U>;

// struct

struct Node
{
    int data;
    uptr<Node> next;
    uptr<Node> prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DualyLinkedList
{
private:
    uptr<Node> head;
    uptr<Node> tail;

public:
    
    //intit
    DualyLinkedList() : head(nullptr), tail(nullptr) {}

    //add node
    Node* addNode(const int &val);

    //rem node
    bool remNode(const int &val);

    //insert node
    Node* insertNode(const int &pos, const int &val);

    //print list
    void printList();

};



