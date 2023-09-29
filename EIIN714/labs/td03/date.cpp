//
// Created by Maxime BILLY on 22/09/2023.
//

#include "date.h"
#include <ctime>

Date::Date() : day(1), month(1), year(1970) {}

Date::Date(long timestamp) {
    // Look at https://en.cppreference.com/w/cpp/chrono/c/localtime
    // And https://en.cppreference.com/w/cpp/chrono/c/tm
    std::tm* localTimeInfo = std::localtime(&timestamp);

    this->day = localTimeInfo->tm_mday;
    this->month = 1 + localTimeInfo->tm_mon;
    this->year = 1900 + localTimeInfo->tm_year;
}

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

Date Date::operator+(int days) {
    Date d = *this;
    
    while (days >= 0) {
        switch (d.month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (days > 31) {
                    d.month++;
                    days -= 31;
                } else {
                    d.day += days;
                    days = 0;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if (days > 30) {
                    d.month++;
                    days -= 30;
                } else {
                    d.day += days;
                    days = 0;
                }
                break;
            case 2:
                if (days > 28) {
                    d.month++;
                    days -= 28;
                } else {
                    d.day += days;
                    days = 0;
                }
                break;
            
        }
    }

    while (days <= 0) {
        switch (d.month) {
            case 1:
            case 2:
                if (days < 0) {
                    d.month--;
                    days += 31;
                } else {
                    d.day -= days;
                    days = 0;
                }
                break;
            case 3:
                if (days < 0) {
                    d.month--;
                    days += 28;
                } else {
                    d.day -= days;
                    days = 0;
                }
                break;
            case 4:
            case 6:
            case 8:
            case 9:
            case 11:
                if (days < 0) {
                    d.month--;
                    days += 31;
                } else {
                    d.day -= days;
                    days = 0;
                }
                break;
            case 5:
            case 7:
            case 10:
            case 12:
                if (days < 0) {
                    d.month--;
                    days += 30;
                } else {
                    d.day -= days;
                    days = 0;
                }
                break;
        }
    }

    while (d.month > 12) {
        d.year++;
        d.month -= 12;
    }

    while (d.month < 1) {
        d.year--;
        d.month += 12;
    }

    return *this;
}

Date Date::operator-(int days) {
    this + (-days);
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

bool operator==(const int &timestamp, const Date &date) {
    return date == Date(timestamp);
}