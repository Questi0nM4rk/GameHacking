#include "DoublyLinkedList.h"


Node* DoublyLinkedList::addNodeStart(const int &val) {
    std::shared_ptr<Node> newNode = std::make_shared<Node>(val);
    
    if (head == nullptr) {
        head = newNode;
        size++;
        return head.get();

    } else if (tail == nullptr) {
        head->next = newNode;
        tail = newNode;
        tail->prev = head;
        size++;
        return tail.get();

    } else {
        std::shared_ptr<Node> current = head->next;

        newNode->next = current;
        head->next = newNode;

        newNode->prev = head;

        size++;
        return newNode.get();
    }
}

Node* DoublyLinkedList::addNodeEnd(const int &val) {
    std::shared_ptr<Node> newNode = std::make_shared<Node>(val);
    
    if (head == nullptr) {
        head = newNode;
        size++;
        return head.get();

    } else if (tail == nullptr) {
        head->next = newNode;
        tail = newNode;
        tail->prev = head;
        size++;
        return tail.get();

    } else {
        tail->next = newNode;
        newNode->prev = tail;

        tail = newNode;

        size++;
        return newNode.get();
    }
}


Node* DoublyLinkedList::insertNode(const int &pos, const int &val) {
    return nullptr;
}


Node* DoublyLinkedList::getNodeByVal(const int &val) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* left = head.get();
    Node* right = tail.get();

    while (left->next.get() != right && right->prev.get() != left && left != nullptr && right != nullptr) {
        if (left->data == val) {
            return left;
        }
        if (right->data == val) {
            return right;
        }

        left = left->next.get();
        right = right->prev.get();
    }

    if (left == right && left != nullptr && left->data == val) {
        return left;
    }

    return nullptr;
}

Node* DoublyLinkedList::getNodeByPos(const int &pos) {
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

    while (left->next.get() != right && right->prev.get() != left && left != nullptr && right != nullptr) {
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


Node* DoublyLinkedList::getHead() const {
    return head.get();
}

Node* DoublyLinkedList::getTail() const {
    return tail.get();
}


uptr<Node> DoublyLinkedList::popNodeByVal(const int &val) {

    Node* node = getNodeByVal(val);

    return popNode(node);
}

uptr<Node> DoublyLinkedList::popNodeByPos(const int &pos) {

    Node* node = getNodeByPos(pos);

    return popNode(node);

}

uptr<Node> DoublyLinkedList::popNode(Node* node) {
    if (head == nullptr) {
        return nullptr;
    }

    if (node->next) {
        node->next->prev = node->prev;
    } else {
        tail = node->prev;
    }

    if (node->prev) {
        node->prev->next = node->next;
    } else {
        head = node->next;
    }

    size--;

    return uptr<Node>(node);

}


std::vector<int> DoublyLinkedList::toArray() const {
    std::vector<int> result;

    Node* current = head.get();
    while (current) {
        result.push_back(current->data);
        current = current->next.get();
    }

    return result;

}


bool DoublyLinkedList::remNodeByVal(const int &val) {

    Node* node = getNodeByVal(val);

    return remNode(node);

}

bool DoublyLinkedList::remNodeByPos(const int &pos) {
    
    Node* node = getNodeByPos(pos);

    return remNode(node);
    
}

bool DoublyLinkedList::remNode(Node* node) {
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
        tail = node->prev;
    }
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        head = node->next;
    }

    size--;

    return true;

}


bool DoublyLinkedList::clearList() {
    if (head == nullptr) {
        return false;
    }

    Node* current = head.get();
    
    while (current) {
        Node* nextNode = current->next.get();
        current->prev.reset(); 
        current->next.reset(); 
        current = nextNode;
    }

    head.reset();
    tail.reset();

    size = 0;

    return true;
    
}

bool DoublyLinkedList::isEmpty() const {
    if (head == nullptr) {
        return true;
    } else {
        return false;
    }
}


bool DoublyLinkedList::swapNodesByVal(const int &val1, const int &val2) {
    return false;
}

bool DoublyLinkedList::swapNodesByPos(const int &pos1, const int &pos2) {
    return false;
}

bool DoublyLinkedList::swapNodes(Node* node1, Node* node2) {
    return false;
}


int DoublyLinkedList::getSize() const {
    return size;
}

void DoublyLinkedList::printList() const {
    Node* current = head.get();

    while (current) {
        std::cout << current->data;

        if (current->next) {
            std::cout << " <--> ";
        }

        current = current->next.get();
    }

    std::cout << std::endl;
}

void DoublyLinkedList::reverseList() {
    if (!head) {
        return;
    }

    std::shared_ptr<Node> current = head->next;
    std::shared_ptr<Node> temp = nullptr;

    std::shared_ptr<Node> tailTmp = tail;
    tail = head;
    head = tailTmp;
    tailTmp = nullptr;

    while (current) {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        current = temp;
    }
}

DoublyLinkedList::~DoublyLinkedList() {
    clearList();
}