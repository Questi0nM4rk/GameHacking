#include "SinglyLinkedList.h"


//add node
Node* SinglyLinkedList::addNodeStart(const int &val) {
    uptr<Node> newNode = std::make_unique<Node>(val);                           // allocate new Node
                                                                                
    if (head == nullptr) {                                                      // is it the first Node?
        head = std::move(newNode);                                              // add the newNode as the head
        size++;
        return head.get();
    }

    else if(tail == nullptr) {                                                  // make sure its the second node added because its gonna be the last
        head->next = std::move(newNode);
        tail = head->next.get();
        size++;
        return tail;
    }

    else {                                                                      // it is not a first node... just to have O(1) we add the new node to the beggining after the head
        newNode->next = std::move(head->next);                                  // make the newNode point to the 1st node in list
        head->next = std::move(newNode);                                        // make the head point to the newNode
        size++;
        return head->next.get();
    }
}


Node* SinglyLinkedList::addNodeEnd(const int &val) {
    uptr<Node> newNode = std::make_unique<Node>(val);

    if (head == nullptr) {
        head = std::move(newNode);
        size++;
        return head.get();
    }

    else if (tail == nullptr) {
        head->next = std::move(newNode);
        tail = head->next.get();
        size++;
        return tail;
    }

    else {
        tail->next = std::move(newNode);
        tail = tail->next.get();
        size++;
        return tail;
    }
    
}


Node* SinglyLinkedList::getNodeByVal(const int &val) {
    if (!head)
        return nullptr;

    Node* curr = head.get();

    while(curr) {
        if (curr->data == val) {
            return curr;
        }

        curr = curr->next.get();
    }

    return nullptr;

}


Node* SinglyLinkedList::getNodeByPos(const int &pos) {
    if (!head || pos < 0 || pos > size)
        return nullptr;

    Node* curr = head.get();
    int i = 0;

    while (curr) {
        if (i == pos) {
            return curr;
        }

        i++;
        curr = curr->next.get();
    }

    return nullptr;

}


uptr<Node> SinglyLinkedList::popNodeByVal(const int &val) {
    if (!head)
        return nullptr;

    Node* node = getNodeByVal(val);

    return popNode(node);
}


uptr<Node> SinglyLinkedList::popNodeByPos(const int &pos) {
    if (!head || pos < 0 || pos > size)
        return nullptr;

    Node* node = getNodeByPos(pos);
    return popNode(node);
}


uptr<Node> SinglyLinkedList::popNode(Node* node) {
    if (!head || !node)
        return nullptr;

    uptr<Node> poppedNode;

    if (node == head.get()) {
        poppedNode = std::move(head);
        head = std::move(poppedNode->next);
        size--;
        return std::move(poppedNode);
    }

    Node* curr = head->next.get();
    Node* prev = head.get();

    while (curr) {
        if (curr == node) {
            poppedNode = std::move(prev->next);
            prev->next = std::move(poppedNode->next);
            size--;
            return std::move(poppedNode);
        }

        prev = curr;
        curr = curr->next.get();
    }

    return nullptr;

}


int SinglyLinkedList::getSize() const {
    return size;
}


//remove node - removes the node with given value
bool SinglyLinkedList::remNodeByVal(const int &val) {
    if (!head)
        return false;

    Node* prev = head.get();                                                    // get first node as the prev
    Node* curr = head->next.get();                                              // get the next node as the curr

    if (head->data == val) {                                                    // is head the node we wanna remove?
        head = std::move(head->next);                                           // just make the new head the next node
        size--;
        return true;
    }

    while (curr) {
        if (curr->data == val) {                                                // did we find the node?
            prev->next = std::move(curr->next);                                 // remove the curr by changing the next ptr
            size--;
            return true;
        }

        prev = curr;
        curr = curr->next.get();
    }

    return false;
}


bool SinglyLinkedList::remNodeByPos(const int &pos) {
    if (!head || pos < 0 || pos > size)
        return false;

    Node* node = getNodeByPos(pos);

    return remNode(node);
}


bool SinglyLinkedList::remNode(Node* node) {
    if (!head || !node)
        return false;

    Node* prev = head.get();
    Node* curr = head->next.get();

    if (node == head.get()) {
        uptr<Node> next = std::move(head->next);
        head.release();
        head = std::move(next);
        size--;
        return true;
    }

    while (curr) {
        if (node == curr) {
            prev->next.release();
            prev->next = std::move(curr->next);
            size--;
            return true;
        }

        prev = curr;
        curr = curr->next.get();
    }

    return false;

}

//insert node to pos - 0,1,2,3,4,....
Node* SinglyLinkedList::insertNode(const int &pos, const int &val) {

    if (pos < 0 || !head || pos > size)                                         // if the pos isnt in list = fck off
        return nullptr;

    uptr<Node> newNode = std::make_unique<Node>(val);

    if (pos == 0) {                                                             // do you want to insert the node as head?
        newNode->next = std::move(head);                                        // newNode next is gonna be the head which makes the newNode the head
        head = std::move(newNode);                                              // tell our class that the new head in the newNode
        size++;
        return head.get();
    }

    Node* prev = head.get();
    Node* curr = head->next.get();
    int i = 1;

    while (curr) {                                                              // iterate over the list untill its null
        if (i == pos) {                                                         // if we are at the pos change the ptrs
            newNode->next = std::move(prev->next);                              // the newNodes next ptr will be the prev next ptr = curr
            prev->next = std::move(newNode);                                    // the prev next will be the newNode, replacing the curr node in the list
            size++;
            return prev->next.get();                                            
        }

        i++;
        prev = curr;
        curr = curr->next.get();
    }

    return nullptr;
}


Node* SinglyLinkedList::getHead() const {
    return head.get();
}


Node* SinglyLinkedList::getTail() const {
    return tail;
}


std::vector<int> SinglyLinkedList::toArray() const {
    std::vector<int> array;
    
    if (!head)
        return array;
    
    Node* curr = head.get();

    while (curr) {
        array.push_back(curr->data);
        curr = curr->next.get();
    }

    return array;

}


bool SinglyLinkedList::isEmpty() const {
    if (!head || size == 0)
        return false;
    else
        return true;
}


//print list
void SinglyLinkedList::printList() const {
    Node* current = head.get();

    while (current) {
        std::cout << current->data;

        if (current->next) {
            std::cout << "->";
        }

        current = current->next.get();
    }

    std::cout << std::endl;
}


bool SinglyLinkedList::clearList() {
    try{

        while (head) {
            head = std::move(head->next);
        }

        size = 0;
        return true;
    }
    catch(...){
        return false;
    }
}


void SinglyLinkedList::reverseList() {
    Node* prev = nullptr;
    Node* current = head.get();
    Node* next = nullptr;

    while (current) {
        next = current->next.get();
        current->next.release();
        current->next.reset(prev);
        prev = current;
        current = next;
    }

    head = std::move(uptr<Node>(prev));
}


bool SinglyLinkedList::swapNodesByPos(const int &pos1, const int &pos2) {
    if (!head || pos1 < 0 || pos1 > size || pos2 < 0 || pos2 > size)
        return false;

    Node* node1 = getNodeByPos(pos1);
    Node* node2 = getNodeByPos(pos1);

    if (!node1 || !node2)
        return false;

    return swapNodes(node1, node2);
}


bool SinglyLinkedList::swapNodesByVal(const int &val1, const int &val2) {

}


bool SinglyLinkedList::swapNodes(Node* node1, Node* node2) {

}


SinglyLinkedList::~SinglyLinkedList() {
    clearList();
}