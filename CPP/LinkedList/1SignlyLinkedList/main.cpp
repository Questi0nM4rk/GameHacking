#include "SinglyLinkedList.h"


int main() {

    bool isRunning = true;
    SinglyLinkedList SLL;
    std::vector<int> array;

    while(isRunning){

        std::cout << "Select an option: " << std::endl;
        std::cout << "1 - Add node to start of the list, using value" << std::endl;
        std::cout << "2 - Add node to end of the list, using value" << std::endl;
        std::cout << "3 - Remove node from list - value, pos or node ptr" << std::endl;
        std::cout << "4 - Insert node to list, using index from 0" << std::endl;
        std::cout << "5 - Pop node from list - value, pos or node ptr" << std::endl;
        std::cout << "6 - Swap nodes - value, pos or node ptr" << std::endl;
        std::cout << "7 - Get node ptr from value or pos" << std::endl;
        std::cout << "8 - Convert to array" << std::endl;
        std::cout << "9 - Get size of the list" << std::endl;
        std::cout << "10 - Is empty" << std::endl;
        std::cout << "11 - Reverse the list" << std::endl;
        std::cout << "12 - Print the list" << std::endl;
        std::cout << "13 - Clear the list" << std::endl;
        std::cout << "14 - Exit" << std::endl << std::endl;
        
        int opt;
        std::cin >> opt;

        switch (opt)
        {
            char pickOpt;
            int val, pos, size;
            Node* nodePtr;
            Node* holdPtr;
            bool bRet;

            case 1: // Add node start
                std::cout << "What value should the node have? " << std::endl;
                std::cin >> val;

                nodePtr = SLL.addNodeStart(val);

                if(nodePtr)
                    std::cout << "Node added!" << std::endl;

                else
                    std::cout << "Failed!" << std::endl;

            break;
            
            case 2: // Add node end
                std::cout << "What value should the node have? " << std::endl;
                std::cin >> val;

                nodePtr = SLL.addNodeEnd(val);

                if(nodePtr)
                    std::cout << "Node added!" << std::endl;

                else
                    std::cout << "Failed!" << std::endl;

            break;

            case 3: // Remove node
                

                std::cout << "What value does the node have? " << std::endl;
                std::cin >> val;

                bRet = SLL.remNodeByVal(val);

                if(bRet)
                    std::cout << "Node removed!" << std::endl;

                else
                    std::cout << "Failed!" << std::endl;

            break;

            case 4: // Insert node
                std::cout << "Where to insert the node? index starting at 0: " << std::endl;
                std::cin >> pos;

                std::cout << "What value should the node have? " << std::endl;
                std::cin >> val;

                nodePtr = SLL.insertNode(pos, val); 

                if(nodePtr)
                    std::cout << "Node inserted!" << std::endl;

                else
                    std::cout << "Failed!" << std::endl;

            break;
            
            case 5: // Pop node
                
            break;

            case 6: // Swap nodes
                SLL.clearList();
                std::cout << "List cleared!" << std::endl;

            break;

            case 7: // Get node ptr
                
            break;
            
            case 8: // Convert to array
                array = SLL.toArray();

                if (!array.empty())
                    std::cout << "Converted!" << std::endl;

                else
                    std::cout << "Failed!" << std::endl;

            break;
            

            case 9: // Get size
                size = SLL.getSize();

                std::cout << "The size is: " + size << std::endl;

            break;
            

            case 10: // Is empty
                bRet = SLL.isEmpty();

                if (bRet)
                    std::cout << "List is empty!" << std::endl;
                
                else 
                    std::cout << "Failed!";

            break;
            

            case 11: // Reverse
                SLL.reverseList();
                std::cout << "List reversed!" << std::endl;

            break;
            

            case 12: // Print the list
                SLL.printList();
                std::cout << std::endl;

            break;
            

            case 13: // Clear
                bRet = SLL.clearList();

                if (bRet) 
                    std::cout << "List cleared!" << std::endl;

                else 
                    std::cout << "Failed!";
                
            break;
            
            case 14: // Exit
                std::cout << "Exitted" << std::endl;
                isRunning = false;

            break;
            
            default:
                std::cout << "Invalid option!" << std::endl;
                break;
        }

    }

    return EXIT_SUCCESS;
}