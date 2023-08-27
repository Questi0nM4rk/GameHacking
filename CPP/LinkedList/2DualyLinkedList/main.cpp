#include "DualyLinkedList.h"

int main() {
    
    DualyLinkedList DLL;

    for (int i = 20; i > 0; i--) {
        DLL.addNodeEnd(i);
    }

    std::cout << std::endl;

    DLL.printList();

    std::cout << std::endl;
    
    DLL.reverseList();

    std::cout << std::endl;

    DLL.printList();

    return EXIT_SUCCESS;
}