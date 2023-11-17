//
// Created by Maxime BILLY on 17/11/2023.
//
#ifndef _LIST_COPY_H_
#define _LIST_COPY_H_

#include <iostream>

class List
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node *head;

public:
    List() : head(nullptr) {}

    // Destructor
    ~List()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Copy constructor
    List(const List &other)
    {
        head = nullptr; // Initialize the new list

        Node *otherPtr = other.head;

        while (otherPtr != nullptr)
        {
            append(otherPtr->data);
            otherPtr = otherPtr->next;
        }
    }

    // Assignment operator
    List &operator=(const List &other)
    {
        if (this != &other)
        {
            // Clear the current content
            while (head != nullptr)
            {
                Node *temp = head;
                head = head->next;
                delete temp;
            }

            // Copy the content of the other list
            Node *otherPtr = other.head;

            while (otherPtr != nullptr)
            {
                append(otherPtr->data);
                otherPtr = otherPtr->next;
            }
        }

        return *this;
    }

    // Function to check if the list is empty
    bool is_empty() const
    {
        return head == nullptr;
    }

    // Function to append a value to the end of the list
    void append(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to prepend a value to the beginning of the list
    void prepend(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to get and remove the first element of the list
    int get_first()
    {
        if (head != nullptr)
        {
            int data = head->data;
            Node *temp = head;
            head = head->next;
            delete temp;
            return data;
        }
        else
        {
            // Handle the case when the list is empty
            std::cerr << "Error: Attempting to get the first element of an empty list." << std::endl;
            return 0; // You might want to throw an exception here or handle it differently
        }
    }

    // Overload << operator to print the list
    friend std::ostream &operator<<(std::ostream &out, const List &list)
    {
        List::Node *current = list.head;

        while (current != nullptr)
        {
            out << current->data << " ";
            current = current->next;
        }

        return out;
    }

    // Function to get the maximum element in the list
    int &max()
    {
        Node *temp = head;
        int *maxValue = &(temp->data);

        while (temp != nullptr)
        {
            if (temp->data > *maxValue)
            {
                *maxValue = temp->data;
            }
            temp = temp->next;
        }

        return *maxValue;
    }

    // Overload + operator for list concatenation
    friend List operator+(const List &lhs, const List &rhs)
    {
        List result = lhs;

        Node *rhsPtr = rhs.head;
        while (rhsPtr != nullptr)
        {
            result.append(rhsPtr->data);
            rhsPtr = rhsPtr->next;
        }

        return result;
    }

    // Overload * operator for odd-even shuffle
    friend List operator*(const List &lhs, const List &rhs)
    {
        List result;

        Node *lhsPtr = lhs.head;
        Node *rhsPtr = rhs.head;

        while (lhsPtr != nullptr && rhsPtr != nullptr)
        {
            result.append(lhsPtr->data);
            result.append(rhsPtr->data);
            lhsPtr = lhsPtr->next;
            rhsPtr = rhsPtr->next;
        }

        // If one list is longer than the other, append the remaining elements
        while (lhsPtr != nullptr)
        {
            result.append(lhsPtr->data);
            lhsPtr = lhsPtr->next;
        }

        while (rhsPtr != nullptr)
        {
            result.append(rhsPtr->data);
            rhsPtr = rhsPtr->next;
        }

        return result;
    }
};

#endif // _LIST_COPY_H_

