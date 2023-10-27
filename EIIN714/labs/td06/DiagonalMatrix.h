//
// Created by Maxime BILLY on 27/10/2023.
//

#ifndef TD06_DIAGONALMATRIX_H
#define TD06_DIAGONALMATRIX_H


#include "SquareMatrix.h"

class DiagonalMatrix: public SquareMatrix {
public:
    DiagonalMatrix(int n = 0, double x = 0.0): SquareMatrix(n, 0) {
        for (int i = 0; i < n; ++i) {
            (*this)(i, i) = x;
        }
    }
    explicit DiagonalMatrix(const SquareMatrix& mat): SquareMatrix(mat) {
        for (int i = 0; i < mat.ncols(); ++i) {
            for (int j = 0; j < mat.nlines(); ++j) {
                if (i != j && mat(i, j) != 0) {
                    throw Bad_Dimensions();
                }
            }
        }
    }

    DiagonalMatrix(MVector vector): DiagonalMatrix(vector.size()) {
        for (int i = 0; i < vector.size(); ++i) {
            (*this)(i, i) = vector[i];
        }
    }

    DiagonalMatrix& operator+=(const DiagonalMatrix& mat) {return *this = *this + mat;}
    DiagonalMatrix& operator-=(const DiagonalMatrix& mat) {return *this = *this - mat;}
    DiagonalMatrix& operator*=(const DiagonalMatrix& mat) {return *this = *this * mat;}

    DiagonalMatrix transpose() const {
        return DiagonalMatrix(SquareMatrix(*this).transpose());
    }
    DiagonalMatrix operator~() const {return transpose();}

    friend DiagonalMatrix operator+(const DiagonalMatrix& mat1, const DiagonalMatrix& mat2) {
        return DiagonalMatrix(SquareMatrix(mat1) + SquareMatrix(mat2));
    }
    friend DiagonalMatrix operator-(const DiagonalMatrix& mat1, const DiagonalMatrix& mat2) {
        return DiagonalMatrix(SquareMatrix(mat1) - SquareMatrix(mat2));
    }
    friend DiagonalMatrix operator*(const DiagonalMatrix& mat1, const DiagonalMatrix& mat2) {
        return DiagonalMatrix(SquareMatrix(mat1) * SquareMatrix(mat2));
    }
};


#endif //TD06_DIAGONALMATRIX_H
