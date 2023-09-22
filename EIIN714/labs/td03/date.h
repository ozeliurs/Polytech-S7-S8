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

    Date(int day, int month, int year);

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

    Date operator-(const Date &date) const;

    Date operator++(int);

    Date operator++();

    Date operator--(int);

    Date operator--();

    friend std::ostream &operator<<(std::ostream &os, const Date &date);

    friend std::istream &operator>>(std::istream &is, Date &date);
};


#endif //TD03_DATE_H
