//
// Created by Maxime BILLY on 10/11/2023.
//

#ifndef TD07_CELL_H
#define TD07_CELL_H

class Cell {
private:
    int value;
    Cell *next;
public:
    int &get_value() {
        return this->value;
    }

    void set_next(Cell *next) {
        this->next = next;
    }

    Cell *get_next() {
        return this->next;
    }

    Cell(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

#endif //TD07_CELL_H