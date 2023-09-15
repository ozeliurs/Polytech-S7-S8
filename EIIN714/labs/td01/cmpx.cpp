//
// Created by Maxime BILLY on 15/09/2023.
//

#include <iostream>
#include <vector>

void cmpx(int& a, int& b) {
    if (b > a) {
        int buf = a;
        a = b;
        b = buf;
    }
}

void insert(int number, std::vector<int>& vect) {
    vect.insert(vect.begin(), number);
    for (int i = 0; i < vect.size() - 1; i++) {
        cmpx(vect[i], vect[i + 1]);
    }
}

int main() {
    std::vector<int> vect;
    int number;

    std::cout << "Veuillez entrer un nombre: ";
    std::cin >> number;

    while (number != 0) {
        insert(number, vect);
        std::cout << "Veuillez entrer un nombre: ";
        std::cin >> number;
    }

    for (int i = 0; i < vect.size(); i++) {
        std::cout << vect[i] << " ";
    }

    return 0;
}