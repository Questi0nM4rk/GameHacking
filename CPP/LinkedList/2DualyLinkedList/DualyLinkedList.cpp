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
    if (head == nullptr) {
        return nullptr;
    }

    Node* left = head.get();
    Node* right = tail.get();

    while (left->next != right && right->prev != left && left != nullptr && right != nullptr) {
        if (left->data == val) {
            return left;
        }
        if (right->data == val) {
            return right;
        }

        left = left->next;
        right = right->prev;
    }

    if (left == right && left != nullptr && left->data == val) {
        return left;
    }

    return nullptr;
}

Node* DualyLinkedList::getNodeByPos(const int &pos) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* left = head.get();
    Node* right = tail.get();

    int leftPos = 0;
    int rightPos = size;

    if (pos == 0) {
        return head.get();
    }

    else if (pos == size-1) {
        return tail.get();
    }

    while (left->next != right && right->prev != left && left != nullptr && right != nullptr) {
        if (leftPos == pos) {
            return left;
        }

        if (rightPos == pos) {
            return right;
        }

        leftPos++;
        rightPos--;
    }

    if (leftPos == 0) {
        return left;
    }

    return nullptr;
}


Node* DualyLinkedList::getHead() const {
    return head.get();
}

Node* DualyLinkedList::getTail() const {
    return tail.get();
}


uptr<Node> DualyLinkedList::popNodeByVal(const int &val) {

    Node* node = getNodeByVal(val);

    return popNode(node);
}

uptr<Node> DualyLinkedList::popNodeByPos(const int &pos) {

    Node* node = getNodeByPos(pos);

    return popNode(node);

}

uptr<Node> DualyLinkedList::popNode(Node* node) {
    if (head == nullptr) {
        return nullptr;
    }

    uptr<Node> poppedNode = std::move(uptr<Node>(node));

    if (node->next) {
        node->next->prev = node->prev;
    } else {
        tail = uptr<Node>(node->prev);
    }
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        head = uptr<Node>(node->next);;
    }

    size--;

    return poppedNode;

}


std::vector<int> DualyLinkedList::toArray() const {
    std::vector<int> result;

    Node* current = head.get();
    while (current) {
        result.push_back(current->data);
        current = current->next;
    }

    return result;

}


bool DualyLinkedList::remNodeByVal(const int &val) {

    Node* node = getNodeByVal(val);

    return remNode(node);

}

bool DualyLinkedList::remNodeByPos(const int &pos) {
    
    Node* node = getNodeByPos(pos);

    return remNode(node);
    
}

bool DualyLinkedList::remNode(Node* node) {
    if (head == nullptr) {
        return false;
    }

    if (node == nullptr) {
        return false;
    }

    uptr<Node> poppedNode = std::move(uptr<Node>(node));

    if (node->next) {
        node->next->prev = node->prev;
    } else {
        tail = uptr<Node>(node->prev);
    }
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        head = uptr<Node>(node->next);;
    }

    size--;

    return true;

}


bool DualyLinkedList::clearList() {
    if (head == nullptr) {
        return false;
    }

    uptr<Node> node = std::move(head);

    while (node->next) {
        node = uptr<Node>(node->next);
    }

    head.reset();
    tail.reset();

    size = 0;

    return true;
    
}

bool DualyLinkedList::isEmpty() const {
    if (head == nullptr) {
        return true;
    } else {
        return false;
    }
}


bool DualyLinkedList::swapNodesByVal(const int &val1, const int &val2) {

}

bool DualyLinkedList::swapNodesByPos(const int &pos1, const int &pos2) {

}

bool DualyLinkedList::swapNodes(Node* node1, Node* node2) {

}


int DualyLinkedList::getSize() const {
    return size;
}

void DualyLinkedList::printList() const {
    Node* current = head.get();

    while (current) {
        std::cout << current->data;

        if (current->next) {
            std::cout << "<-->";
        }

        current = current->next;
    }

    std::cout << std::endl;
}

void DualyLinkedList::reverseList() {
    if (head == nullptr || head == tail) {
        return;
    }

    Node* current = head->next;
    Node* temp = nullptr;

    uptr<Node> tailTmp = std::move(tail);
    tail = std::move(head);
    head = std::move(tailTmp);
    tailTmp.reset();

    while (current) {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        current = temp;

    }

}

