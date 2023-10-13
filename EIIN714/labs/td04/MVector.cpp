//
// Created by Maxime BILLY on 06/10/2023.
//

#include "MVector.h"

// === Constructors ===

MVector::MVector() : v() {}

MVector::MVector(unsigned int size, double value) : v(size, value) {}

MVector::MVector(const std::vector<double> &v) : v(v) {}

// === Methods ===

double MVector::norm() {
    double norm = 0;
    for (double i: v) {
        norm += i * i;
    }
    return sqrt(norm);
}

// === Operators ===

bool MVector::operator==(const MVector &m) const {
    return this->v == m.v;
}

MVector MVector::operator+=(const MVector &m) {
    return (*this) = (*this) + m;
}

MVector MVector::operator-=(const MVector &m) {
    return (*this) = (*this) - m;
}

MVector MVector::operator+(const MVector& m) {
    if (this->v.size() != m.v.size()) {
        throw MVector::Bad_Dimensions();
    }

    for (int i = 0; i < this->v.size(); ++i) {
        this->v[i] += m[i];
    }

    return *this;
}

MVector MVector::operator-(const MVector& m) {
    if (this->v.size() != m.v.size()) {
        throw MVector::Bad_Dimensions();
    }

    for (int i = 0; i < this->v.size(); ++i) {
        this->v[i] -= m[i];
    }

    return *this;
}

double operator*(const MVector &m1, const MVector &m2) {
    // Dot product
    if (m1.v.size() != m2.v.size()) {
        throw MVector::Bad_Dimensions();
    }

    double result = 0;

    for (int i = 0; i < m1.v.size(); ++i) {
        result += m1[i] * m2[i];
    }

    return result;
}

double MVector::operator[](int index) const {
    return this->v[index];
}

double &MVector::operator[](int index) {
    return this->v[index];
}

std::ostream &operator<<(std::ostream &os, const MVector& v) {
    os << "[";
    for (int i = 0; i < v.v.size(); ++i) {
        os << v[i];
        if (i != v.v.size() - 1) {
            os << ", ";
        }
    }
    os << "]";

    return os;
}



