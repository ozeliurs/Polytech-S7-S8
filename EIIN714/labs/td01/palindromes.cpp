//
// Created by Maxime BILLY on 15/09/2023.
//

#include <iostream>

int main() {
    std::string input;

    std::cout << "Veuillez entrer un mot: ";
    std::cin >> input;

    bool is_palindrome = true;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] != input[input.length() - i - 1]) {
            std::cout << "Votre mot n'est pas un palindrome.";
            return 0;
        }
    }

    std::cout << "Votre mot est un palindrome.";
    return 0;
}