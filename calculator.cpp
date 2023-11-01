#include "inf_int.h"
#include <iostream>
#include <string>
#include <sstream>





int main() {
    std::string input;
    std::cout << "Input: ";
    while (std::getline(std::cin, input)) {
        if (input == "0") {
            break; // Terminate the program if 0 is entered.
        }

        std::istringstream iss(input);
        inf_int num1, num2, result;
        char op;

        if (iss >> num1 >> op >> num2) {
            result = calculate(num1, op, num2);
            std::cout << "Result: " << result << std::endl;
        }
        else {
            std::cout << "Invalid input format. Please use (integer) (operator) (integer)." << std::endl;
        }

        std::cout << "Input: ";
    }

    return 0;
}