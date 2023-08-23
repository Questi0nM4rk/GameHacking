#include "DualyLinkedList.h"


Node* DualyLinkedList::addNodeStart(const int &val) {
    uptr<Node> newNode = std::make_unique<Node>(val);
    
    if (head == nullptr) {
        head = std::move(newNode);
        size++;
        return head.get();
    }

    else if(tail == nullptr) {
        tail = std::move(newNode);
        head->next = tail.get();
        tail->prev = head.get();

        size++;
        return tail.get();
    }

    else { 
        newNode->next = tail.get();
        tail->prev = newNode.get();
        head->next = newNode.get();
        size++;
        return head->next;
    }
}

Node* DualyLinkedList::addNodeEnd(const int &val) {
    uptr<Node> newNode = std::make_unique<Node>(val);
    
    if (head == nullptr) {
        head = std::move(newNode);
        size++;
        return head.get();
    }

    else if(tail == nullptr) {
        tail = std::move(newNode);
        head->next = tail.get();
        tail->prev = head.get();

        size++;
        return tail.get();
    }

    else { 
        newNode->prev = tail.get();
        tail->next = newNode.get();
        size++;
        return head->next;
    }
}

Node* DualyLinkedList::insertNode(const int &pos, const int &val) {
    
}

Node* DualyLinkedList::getNodeByVal(const int &val) {

}

Node* DualyLinkedList::getNodeByPos(const int &pos) {

}

Node* DualyLinkedList::getHead() const {

}

Node* DualyLinkedList::getTail() const {

}

uptr<Node> DualyLinkedList::popNodeByVal(const int &val) {

}

uptr<Node> DualyLinkedList::popNodeByPos(const int &pos) {

}

uptr<Node> DualyLinkedList::popNode(Node* node) {

}

std::vector<int> DualyLinkedList::toArray() const {

}

bool DualyLinkedList::remNodeByVal(const int &val) {

}

bool DualyLinkedList::remNodeByPos(const int &pos) {

}

bool DualyLinkedList::remNode(Node* node) {

}

bool DualyLinkedList::clearList() {

}

bool DualyLinkedList::isEmpty() const {

}

bool DualyLinkedList::swapNodesByVal(const int &val1, const int &val2) {

}

bool DualyLinkedList::swapNodesByPos(const int &pos1, const int &pos2) {

}

bool DualyLinkedList::swapNodes(Node* node1, Node* node2) {

}

int DualyLinkedList::getSize() const {

}

void DualyLinkedList::printList() const {

}

void DualyLinkedList::reverseList() {
    
}

