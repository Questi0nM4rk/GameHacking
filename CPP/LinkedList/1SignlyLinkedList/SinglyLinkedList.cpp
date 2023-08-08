//#include "../../basic.h"
#include "SinglyLinkedList.h"



//add node
Node* SinglyLinkedList::addNodeStart(const int &val) {
    uptr<Node> newNode = std::make_unique<Node>(val);                           // allocate new Node
                                                                                
    if (head == nullptr) {                                                      // is it the first Node?
        head = std::move(newNode);                                              // add the newNode as the head
        return head.get();
    }

    else {                                                                      // it is not a first node... 
                                                                                // just to have O(1) we add the new node to the beggining after the head
        newNode->next = std::move(head->next);                                  // make the newNode point to the 1st node in list
                                                                                
        head->next = std::move(newNode);                                        // make the head point to the newNode
    }                                                                           // this adds the node to the 1st pos after head

    return head->next.get();                                                    // return the newNode raw ptr
};


Node* SinglyLinkedList::addNodeEnd(const int &val) {
    return nullptr;
}


//remove node - removes the node with given value
bool SinglyLinkedList::remNode(const int &val) {
    Node* prev = head.get();                                                    // get first node as the prev
    Node* curr = head->next.get();                                              // get the next node as the curr

    if (head->data == val) {                                                    // is head the node we wanna remove?
        head = std::move(head->next);                                           // just make the new head the next node
        return true;
    }

    while (curr) {
        if (curr->data == val) {                                                // did we find the node?
            prev->next = std::move(curr->next);                                 // remove the curr by changing the next ptr
            return true;
        }

        prev = curr;
        curr = curr->next.get();
    }

    return false;
};


//insert node to pos - 0,1,2,3,4,....
Node* SinglyLinkedList::insertNode(const int &pos, const int &val) {

    if (pos < 0)                                                                // if the pos isnt in list = fck off
        return NULL;

    uptr<Node> newNode = std::make_unique<Node>(val);

    if (pos == 0) {                                                             // do you want to insert the node as head?
        newNode->next = std::move(head);                                        // newNode next is gonna be the head which makes the newNode the head
        head = std::move(newNode);                                              // tell our class that the new head in the newNode
        return head.get();
    }

    Node* prev = head.get();
    Node* curr = head->next.get();
    int i = 1;

    while (curr) {                                                              // iterate over the list untill its null
        if (i == pos) {                                                         // if we are at the pos change the ptrs
            newNode->next = std::move(prev->next);                              // the newNodes next ptr will be the prev next ptr = curr
            prev->next = std::move(newNode);                                    // the prev next will be the newNode, replacing the curr node in the list
            return prev->next.get();                                            
        }

        i++;
        prev = curr;
        curr = curr->next.get();
    }

    return NULL;
}


//print list
void SinglyLinkedList::printList() {
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

        return true;
    }
    catch(...){
        return false;
    }
}
