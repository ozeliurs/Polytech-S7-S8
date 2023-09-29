//
// Created by Maxime BILLY on 22/09/2023.
//

#include "date.h"
#include <ctime>

// HELPERS

bool isLeapYear(int year) {
    return year % 4 == 0;
}

int day_count(int month, int year) {
    switch (month % 12) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 0:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            if (isLeapYear(year)) {
                return 29;
            } else {
                return 28;
            }
    }
}

// CLASS

Date::Date() : day(1), month(1), year(1970) {}

Date::Date(long timestamp) {
    // Look at https://en.cppreference.com/w/cpp/chrono/c/localtime
    // And https://en.cppreference.com/w/cpp/chrono/c/tm
    std::tm* localTimeInfo = std::localtime(&timestamp);

    this->day = localTimeInfo->tm_mday;
    this->month = 1 + localTimeInfo->tm_mon;
    this->year = 1900 + localTimeInfo->tm_year;
}

Date::Date(int year, int month, int day) : day(day), month(month), year(year) {}

Date Date::operator+(int days) {
    while (days > 0) {
        ++*this;
        days--;
    }

    while (days < 0) {
        --*this;
        days++;
    }

    return *this;
}

Date Date::operator-(int days) {
    this + (-days);
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
    // std::cout << "Comparing " << *this << " and " << date << std::endl;
    return this->day == date.day && this->month == date.month && this->year == date.year;
}

bool Date::operator!=(const Date &date) const {
    return !(*this == date);
}

bool Date::operator<(const Date &date) const {
    return this->year * 10000 + this->month * 100 + this->day < date.year * 10000 + date.month * 100 + date.day;
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

int Date::operator-(const Date &date) const {
    // Return the number of days between two dates
    Date d1 = *this;
    Date d2 = date;
    int days = 0;

    if (d1 < d2) {
        std::cout << d1 << " < " << d2 << std::endl;
        while (d1 != d2) {
            ++d1;
            days++;
        }
    } else {
        std::cout << d1 << " > " << d2 << std::endl;
        while (d1 != d2) {
            --d1;
            days--;
        }
    }

    return days;
}

Date Date::operator++() {
    if (this->day == day_count(this->month, this->year)) {
        this->day = 1;
        if (this->month == 12) {
            this->month = 1;
            this->year++;
        } else {
            this->month++;
        }
    } else {
        this->day++;
    }

    return *this;
}

Date Date::operator++(int) {
    Date d = *this;
    ++*this;
    return d;
}

Date Date::operator--() {
    if (this->day == 1) {
        if (this->month == 1) {
            this->month = 12;
            this->year--;
        } else {
            this->month--;
        }
        this->day = day_count(this->month, this->year);
    } else {
        this->day--;
    }

    return *this;
}

Date Date::operator--(int) {
    Date d = *this;
    *this -= 1;
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

bool operator==(const int &timestamp, const Date &date) {
    return date == Date(timestamp);
}