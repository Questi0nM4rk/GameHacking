#include "SinglyLinkedList.h"


int main() {

    bool b = true;
    SinglyLinkedList SLL;

    while(b){

        std::cout << "Select an option: " << std::endl;
        std::cout << "1 - Add node to list, using value" << std::endl;
        std::cout << "2 - Remove node to list, using value" << std::endl;
        std::cout << "3 - Insert node to list, using index from 0" << std::endl;
        std::cout << "4 - Print the list" << std::endl;
        std::cout << "5 - Exit" << std::endl << std::endl;
        
        int opt;
        std::cin >> opt;

        switch (opt)
        {
            int val, pos;
            Node* ret;
            bool ret1;

            case 1:
                std::cout << "What value should the node have? " << std::endl;
                std::cin >> val;

                ret = SLL.addNode(val);

                if(ret)
                    std::cout << "Node added!" << std::endl;

                else
                    std::cout << "Failed!" << std::endl;

            break;
            
            case 2:
                std::cout << "What value does the node have? " << std::endl;
                std::cin >> val;

                ret1 = SLL.remNode(val);

                if(ret1)
                    std::cout << "Node removed!" << std::endl;

                else
                    std::cout << "Failed!" << std::endl;

            break;

            case 3:
                std::cout << "Where to insert the node? index starting at 0: " << std::endl;
                std::cin >> pos;

                std::cout << "What value should the node have? " << std::endl;
                std::cin >> val;

                ret = SLL.insertNode(val, pos);

                if(ret)
                    std::cout << "Node inserted!" << std::endl;

                else
                    std::cout << "Failed!" << std::endl;

            break;
            
            case 4:
                SLL.printList();
                std::cout << std::endl;
            break;

            case 5:
                std::cout << "Exitted" << std::endl;
                b = false;
            break;
            
            default:
                b = false;
            break;
        }

    }

    return EXIT_SUCCESS;
}