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
    Node* tail = nullptr;
    int size = 0;

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    Node* addNodeStart(const int &val); //done

    Node* addNodeEnd(const int &val);   //done

    Node* insertNode(const int &pos, const int &val);   //done

    Node* getNode(const int &val);  //done

    Node* getNode(const int &pos);  //done

    uptr<Node> popNode(const int &val);
   
    uptr<Node> popNode(const int &pos);

    uptr<Node> popNode(Node* node);   

    bool remNode(const int &val);   //done

    bool remNode(const int &pos);

    bool remNode(Node* node);

    bool clearList();   //done

    int getSize();  //done

    void printList();   //done
};