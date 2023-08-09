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

    else {                                                                      // it is not a first node... 
                                                                                // just to have O(1) we add the new node to the beggining after the head
        newNode->next = std::move(head->next);                                  // make the newNode point to the 1st node in list
        head->next = std::move(newNode);                                        // make the head point to the newNode
        size++;
        return head->next.get();
    }
};


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


Node* SinglyLinkedList::getNode(const int &val) {
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


Node* SinglyLinkedList::getNode(const int &pos) {
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


uptr<Node> SinglyLinkedList::popNode(const int &val) {
    if (!head)
        return nullptr;

    uptr<Node> poppedNode;

    if (val == head->data) {
        poppedNode = std::move(head);
        head = std::move(poppedNode->next);
        return std::move(poppedNode);
    }

    Node* curr = head->next.get();
    Node* prev = head.get();




}


uptr<Node> SinglyLinkedList::popNode(const int &pos) {
    if (!head || pos < 0 || pos > size)
        return nullptr;

    uptr<Node> poppedNode;

    if (pos == 0) {
        poppedNode = std::move(head);
        head = std::move(poppedNode->next);
        return std::move(poppedNode);
    }

    Node* curr = head->next.get();
    Node* prev = head.get();
    int i = 1;

    while (curr) {
        if (i == pos) {
            poppedNode = std::move(prev->next);
            prev->next = std::move(poppedNode->next);
            return std::move(poppedNode);
        }    
        i++;
        prev = curr;
        curr = curr->next.get();
    }

    return nullptr;

}


int SinglyLinkedList::getSize() {
    return size;
}


//remove node - removes the node with given value
bool SinglyLinkedList::remNode(const int &val) {
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
};


//insert node to pos - 0,1,2,3,4,....
Node* SinglyLinkedList::insertNode(const int &pos, const int &val) {

    if (pos < 0 || !head || pos > size)                                         // if the pos isnt in list = fck off
        return NULL;

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

        size = 0;
        return true;
    }
    catch(...){
        return false;
    }
}
