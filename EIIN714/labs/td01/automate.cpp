//
// Created by Maxime BILLY on 15/09/2023.
//

#include <iostream>
#include <vector>
#include <ctime>

#define N 200


void display(std::vector<bool> v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << (v[i] ? "X" : " ");
    }
    std::cout << std::endl;
}


int main() {
    srand(time(nullptr));
    std::vector<bool> current(N), next(N);

    // Random distribution
    for (int i = 0; i < current.size(); i++) {
        current[i] = rand() % 2;
    }

    // Display
    display(current);

    for (int round = 0; round < 10; round++) {

        // Next generation
        for (int i = 0; i < current.size(); i++) {
            next[i] = current[i - 1] & current[i + 1];
        }

        for (int i = 0; i < current.size(); i++) {
            current[i] = next[i];
        }

        // Display
        display(next);
    }
}