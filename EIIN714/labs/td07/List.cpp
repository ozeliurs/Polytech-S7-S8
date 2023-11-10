//
// Created by Maxime BILLY on 10/11/2023.
//

#include "List.h"

List::List() {
    this->head = nullptr;
    this->tail = nullptr;
}

int List::get_first() {
    Cell *tmp = this->head;

    this->head = this->head->get_next();

    int value = tmp->get_value();
    delete tmp;

    return value;
}

int List::get_middle_value() {
    int middle = this->length() / 2;

    Cell *previous = this->head;
    Cell *current = this->head;

    for (int i = 0; i < middle; i++) {
        previous = current;
        current = current->get_next();
    }

    int value = current->get_value();

    previous->set_next(current->get_next());
    delete current;

    return value;
}

int List::get_last() {
    Cell *tmp = this->tail;

    Cell *current = this->head;
    while (current->get_next()->get_next() != nullptr) {
        current = current->get_next();
    }
    this->tail = current;
    current->set_next(nullptr);

    int value = tmp->get_value();
    delete tmp;

    return value;
}

bool List::is_empty() {
    return this->head == nullptr;
}

int List::length() {
    int length = 0;
    Cell *current = this->head;
    while (current != nullptr) {
        length++;
        current = current->get_next();
    }
    return length;
}

void List::append(int value) {
    Cell *new_cell = new Cell(value);

    if (this->is_empty()) {
        this->head = new_cell;
        this->tail = new_cell;
    } else {
        this->tail->set_next(new_cell);
        this->tail = new_cell;
    }
}


void List::insert(int value) {
    Cell *new_cell = new Cell(value);

    if (this->is_empty()) {
        this->head = new_cell;
        this->tail = new_cell;
        return;
    }

    Cell *current = this->head;

    if (current->get_value() > value) {
        new_cell->set_next(current);
        this->head = new_cell;
        return;
    }

    while (current->get_next() != nullptr) {
        if (current->get_next()->get_value() > value) {
            break;
        }
        current = current->get_next();
    }

    if (current->get_next() == nullptr) {
        this->tail = new_cell;
    }

    new_cell->set_next(current->get_next());
    current->set_next(new_cell);
}


void List::prepend(int value) {
    Cell *new_cell = new Cell(value);

    if (this->is_empty()) {
        this->head = new_cell;
        this->tail = new_cell;
    } else {
        new_cell->set_next(this->head);
        this->head = new_cell;
    }
}

int &List::max() {
    return this->tail->get_value();
}


void List::sort() {
    // HINT: use get_first() and insert()
    List sorted_list;

    while (!this->is_empty()) {
        sorted_list.insert(this->get_first());
    }

    this->head = sorted_list.head;
    this->tail = sorted_list.tail;
}


void List::mirror() {
    List reversed_list;

    while (!this->is_empty()) {
        reversed_list.prepend(this->get_first());
    }

    this->head = reversed_list.head;
    this->tail = reversed_list.tail;
}

std::ostream &operator<<(std::ostream &os, const List &list) {
    os << "List: ";

    Cell *current = list.head;

    for (Cell *current = list.head; current != nullptr; current = current->get_next()) {
        os << current->get_value() << " ";
    }

    return os;
}
