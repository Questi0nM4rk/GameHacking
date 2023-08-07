#include "basic.h"

void print(const std::string& message) {
    std::cout << message << std::endl;
}

std::string input(const std::string& message = "") {
    if (!message.empty()){
        print(message);
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string input;
    std::getline(std::cin, input);

    return input;
}