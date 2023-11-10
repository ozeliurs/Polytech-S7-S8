//
// Created by Maxime BILLY on 10/11/2023.
//

#ifndef TD07_LIST_H
#define TD07_LIST_H

#include <iostream>
#include "Cell.h"


class List {
private:
    Cell *head;
    Cell *tail;
public:
    List();

    int get_first();
    int get_last();

    bool is_empty();
    int length();
    int get_middle_value();

    void append(int value);
    void insert(int value);
    void prepend(int value);

    int &max();

    void sort();
    void mirror();

    friend std::ostream &operator<<(std::ostream &os, const List &list);
};


#endif //TD07_LIST_H
