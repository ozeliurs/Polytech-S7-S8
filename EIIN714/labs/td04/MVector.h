//
// Created by Maxime BILLY on 06/10/2023.
//

#ifndef TD04_MVECTOR_H
#define TD04_MVECTOR_H

#include <vector>
#include <iostream>


class MVector {
public:
    std::vector<double> v;

    MVector();
    MVector(unsigned int size, double value);
    MVector(const std::vector<double> &v);

    double norm();

    bool operator==(const MVector& m) const;

    MVector operator+=(const MVector& m);
    MVector operator-=(const MVector& m);

    MVector operator+(const MVector& m);
    MVector operator-(const MVector& m);
    friend double operator*(const MVector& m1, const MVector& m2);

    double operator[](int index) const;
    double &operator[](int index);

    friend std::ostream& operator<<(std::ostream& os, const MVector& v);

    class Bad_Dimensions : public std::exception {};
};


#endif //TD04_MVECTOR_H
