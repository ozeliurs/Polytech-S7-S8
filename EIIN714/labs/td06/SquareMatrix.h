//
// Created by Maxime BILLY on 27/10/2023.
//

#ifndef TD06_SQUAREMATRIX_H
#define TD06_SQUAREMATRIX_H


#include "Matrix.h"

class SquareMatrix : public Matrix {
public:
    SquareMatrix(int n = 0, double x = 0.0) : Matrix(n, n, x) {}

    explicit SquareMatrix(const Matrix &mat) : Matrix(mat) {
        if (mat.ncols() != mat.nlines()) {
            throw std::invalid_argument("Matrix is not square");
        }
    }

    SquareMatrix &operator+=(const SquareMatrix &mat) { return *this = *this + mat; }

    SquareMatrix &operator-=(const SquareMatrix &mat) { return *this = *this - mat; }

    SquareMatrix &operator*=(const SquareMatrix &mat) { return *this = *this * mat; }

    SquareMatrix transpose() const {
        return SquareMatrix(Matrix(*this).transpose());
    }

    SquareMatrix operator~() const { return transpose(); }

    friend SquareMatrix operator+(const SquareMatrix &mat1, const SquareMatrix &mat2) {
        return SquareMatrix(Matrix(mat1) + Matrix(mat2));
    }

    friend SquareMatrix operator-(const SquareMatrix &mat1, const SquareMatrix &mat2) {
        return SquareMatrix(Matrix(mat1) - Matrix(mat2));
    }

    friend SquareMatrix operator*(const SquareMatrix &mat1, const SquareMatrix &mat2) {
        return SquareMatrix(Matrix(mat1) * Matrix(mat2));
    }

    int det() {
        if (nlines() == 1) {
            return (*this)(0, 0);
        }

        int result = 0;
        for (int i = 0; i < nlines(); ++i)
            result += pow(-1, i) * (*this)(0, i) * submatrix(0, i).det();


        return result;
    }

    // Dark magic
    SquareMatrix submatrix(int i, int j) {
        SquareMatrix result(nlines() - 1);
        int x = 0, y = 0;
        for (int k = 0; k < nlines(); ++k) {
            if (k != i) {
                for (int l = 0; l < nlines(); ++l) {
                    if (l != j) {
                        result(x, y) = (*this)(k, l);
                        ++y;
                    }
                }
                ++x;
            }
            y = 0;
        }
        return result;
    }
};


#endif //TD06_SQUAREMATRIX_H
