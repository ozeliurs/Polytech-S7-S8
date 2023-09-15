//
// Created by Maxime BILLY on 15/09/2023.
//

#include <iostream>

int main() {
    int sum = 0, count = 0, buf;

    std::cout << "Veuillez entrer une suite de nombres: ";

    while (std::cin >> buf) {
        sum += buf;
        count += 1;
    }

    std::cout << "Votre moyenne est: " << (sum / count) << std::endl;
    return 0;
}