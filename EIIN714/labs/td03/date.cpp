//
// Created by Maxime BILLY on 22/09/2023.
//

#include "date.h"
#include <ctime>

Date::Date() : day(1), month(1), year(1970) {}

Date::Date(long timestamp) {
    // use localtime to convert timestamp to day, month and year

    std::cout << "TODO" << std::endl;
}

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

Date Date::operator+(int days) {
    this->day += days;
    return *this;
}

Date Date::operator-(int days) {
    this->day -= days;
    return *this;
}

Date Date::operator+=(int days) {
    *this = *this + days;
    return *this;
}

Date Date::operator-=(int days) {
    *this = *this - days;
    return *this;
}

bool Date::operator==(const Date &date) const {
    return this->day == date.day && this->month == date.month && this->year == date.year;
}

bool Date::operator!=(const Date &date) const {
    return !(*this == date);
}

bool Date::operator<(const Date &date) const {
    return this->day < date.day && this->month < date.month && this->year < date.year;
}

bool Date::operator<=(const Date &date) const {
    return *this < date || *this == date;
}

bool Date::operator>(const Date &date) const {
    return !(*this <= date);
}

bool Date::operator>=(const Date &date) const {
    return !(*this < date);
}

Date Date::operator-(const Date &date) const {
    Date d;
    d.day = this->day - date.day;
    d.month = this->month - date.month;
    d.year = this->year - date.year;
    return d;
}

Date Date::operator++() {
    this->day++;
    return *this;
}

Date Date::operator++(int) {
    Date d = *this;
    this->day++;
    return d;
}

Date Date::operator--() {
    this->day--;
    return *this;
}

Date Date::operator--(int) {
    Date d = *this;
    this->day--;
    return d;
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << date.day << "/" << date.month << "/" << date.year;
    return os;
}

std::istream &operator>>(std::istream &is, Date &date) {
    std::string input;

    is >> input;

    date.year = std::stoi(input.substr(0, 4));
    date.month = std::stoi(input.substr(5, 2));
    date.day = std::stoi(input.substr(8, 2));

    return is;
}