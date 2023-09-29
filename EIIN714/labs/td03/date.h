//
// Created by Maxime BILLY on 22/09/2023.
//

#ifndef TD03_DATE_H
#define TD03_DATE_H

#include <iostream>

class Date {
private:
    int day, month, year;
public:
    Date();

    Date(long timestamp);

    Date(int year, int month, int day);

    Date operator+(int days);

    Date operator-(int days);

    Date operator+=(int days);

    Date operator-=(int days);

    bool operator==(const Date &date) const;

    bool operator!=(const Date &date) const;

    bool operator<=(const Date &date) const;

    bool operator<(const Date &date) const;

    bool operator>=(const Date &date) const;

    bool operator>(const Date &date) const;

    int operator-(const Date &date) const;

    Date operator++(int);

    Date operator++();

    Date operator--(int);

    Date operator--();

    friend std::ostream &operator<<(std::ostream &os, const Date &date);

    friend std::istream &operator>>(std::istream &is, Date &date);

    friend bool operator==(const int &timestamp, const Date &date);
};


#endif //TD03_DATE_H
