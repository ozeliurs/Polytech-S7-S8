//
// Created by Maxime BILLY on 13/10/2023.
//

#ifndef TD05_MATRIX_H
#define TD05_MATRIX_H


#include <vector>
#include "MVector.h"

class Matrix {
    std::vector<MVector> _matrix;

public:
    Matrix();
    Matrix(unsigned long nbLines, unsigned long nbCols, double value = 0.0);
    Matrix(const MVector& mvector);

    Matrix transpose() const;
    Matrix operator~() const;

    MVector line(int i) const;
    MVector column(int j) const;

    bool operator==(const Matrix& matrix) const;

    Matrix& operator+=(const Matrix& matrix);
    Matrix& operator-=(const Matrix& matrix);
    Matrix& operator*=(const Matrix& matrix);

    Matrix operator+(const Matrix& matrix) const;
    Matrix operator-(const Matrix& matrix) const;
    Matrix operator*(const Matrix& matrix) const;

    double& operator()(int i, int j);

    Matrix& operator=(const Matrix& matrix);

    operator MVector() const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

    class Bad_Dimensions : std::exception {};
};


#endif //TD05_MATRIX_H
