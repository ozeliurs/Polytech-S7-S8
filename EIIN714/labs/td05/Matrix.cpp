//
// Created by Maxime BILLY on 13/10/2023.
//

#include "Matrix.h"

Matrix::Matrix() : _matrix() {}

Matrix::Matrix(unsigned long nbLines, unsigned long nbCols, double value) : _matrix(nbLines, MVector(nbCols, value)) {}

Matrix::Matrix(const MVector &mvector) : _matrix(1, mvector) {}

Matrix Matrix::transpose() const {
    Matrix mat = Matrix(_matrix[0].size(), _matrix.size(), 0.0);

    for (int i = 0; i < _matrix.size(); ++i) {
        for (int j = 0; j < _matrix[0].size(); ++j) {
            mat(j, i) = _matrix[i][j];
        }
    }

    return mat;
}

Matrix Matrix::operator~() const {
    return transpose();
}

MVector Matrix::line(int i) const {
    return _matrix[i];
}

MVector Matrix::column(int j) const {
    MVector mvector = MVector(_matrix.size(), 0.0);

    for (int i = 0; i < _matrix.size(); ++i) {
        mvector[i] = _matrix[i][j];
    }

    return mvector;
}

bool Matrix::operator==(const Matrix &matrix) const {
    if (_matrix.size() != matrix._matrix.size() || _matrix[0].size() != matrix._matrix[0].size()) {
        return false;
    }

    for (int i = 0; i < _matrix.size(); ++i) {
        for (int j = 0; j < _matrix[0].size(); ++j) {
            if (_matrix[i][j] != matrix._matrix[i][j]) {
                return false;
            }
        }
    }

    return true;
}

double &Matrix::operator()(int i, int j) {
    return _matrix[i][j];
}

Matrix Matrix::operator+(const Matrix &matrix) const {
    if (_matrix.size() != matrix._matrix.size() || _matrix[0].size() != matrix._matrix[0].size()) {
        throw Bad_Dimensions();
    }

    Matrix mat = Matrix(_matrix.size(), _matrix[0].size(), 0.0);

    for (int i = 0; i < _matrix.size(); ++i) {
        for (int j = 0; j < _matrix[0].size(); ++j) {
            mat(i, j) = _matrix[i][j] + matrix._matrix[i][j];
        }
    }

    return mat;
}

Matrix &Matrix::operator+=(const Matrix &matrix) {
    Matrix mat = *this + matrix;

    *this = mat;

    return *this;
}

Matrix Matrix::operator-(const Matrix &matrix) const {
    if (_matrix.size() != matrix._matrix.size() || _matrix[0].size() != matrix._matrix[0].size()) {
        throw Bad_Dimensions();
    }

    Matrix mat = Matrix(_matrix.size(), _matrix[0].size(), 0.0);

    for (int i = 0; i < _matrix.size(); ++i) {
        for (int j = 0; j < _matrix[0].size(); ++j) {
            mat(i, j) = _matrix[i][j] - matrix._matrix[i][j];
        }
    }

    return mat;
}

Matrix &Matrix::operator-=(const Matrix &matrix) {
    Matrix mat = *this - matrix;

    *this = mat;

    return *this;
}

Matrix Matrix::operator*(const Matrix &matrix) const {
    Matrix mat = Matrix(_matrix.size(), matrix._matrix[0].size(), 0.0);

    for (int i = 0; i < _matrix.size(); ++i) {
        for (int j = 0; j < matrix._matrix[0].size(); ++j) {
            for (int k = 0; k < _matrix[0].size(); ++k) {
                mat(i, j) += _matrix[i][k] * matrix._matrix[k][j];
            }
        }
    }

    return mat;
}

Matrix &Matrix::operator*=(const Matrix &matrix) {
    Matrix mat = *this * matrix;

    *this = mat;

    return *this;
}

Matrix &Matrix::operator=(const Matrix &matrix) {
    _matrix = matrix._matrix;

    return *this;
}

Matrix::operator MVector() const {
    if (_matrix.size() != 1) {
        throw Bad_Dimensions();
    }

    return _matrix[0];
}

std::ostream &operator<<(ostream &os, const Matrix &matrix) {
    os << "[" << std::endl;

    for (const auto & i : matrix._matrix) {
        os << "    " << i << endl;
    }

    os << "]" << endl;

    return os;
}

