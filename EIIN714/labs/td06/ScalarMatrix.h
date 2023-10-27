//
// Created by Maxime BILLY on 27/10/2023.
//

#ifndef TD06_SCALARMATRIX_H
#define TD06_SCALARMATRIX_H


#include "DiagonalMatrix.h"

class ScalarMatrix: public DiagonalMatrix {
public:
    ScalarMatrix(int n = 0, double x = 0.0): DiagonalMatrix(n, x) {}
    explicit ScalarMatrix(const DiagonalMatrix& mat): DiagonalMatrix(mat) {
        int value = mat(0, 0);

        for (int i = 0; i < mat.ncols(); ++i) {
            for (int j = 0; j < mat.nlines(); ++j) {
                if (i == j && mat(i, j) != value) {
                    throw Bad_Dimensions();
                }
            }
        }
    }

    ScalarMatrix& operator+=(const ScalarMatrix& mat) {return *this = *this + mat;}
    ScalarMatrix& operator-=(const ScalarMatrix& mat) {return *this = *this - mat;}
    ScalarMatrix& operator*=(const ScalarMatrix& mat) {return *this = *this * mat;}

    ScalarMatrix transpose() const {
        return ScalarMatrix(DiagonalMatrix(*this).transpose());
    }
    ScalarMatrix operator~() const {return transpose();}

    friend ScalarMatrix operator+(const ScalarMatrix& mat1, const ScalarMatrix& mat2) {
        return ScalarMatrix(DiagonalMatrix(mat1) + DiagonalMatrix(mat2));
    }
    friend ScalarMatrix operator-(const ScalarMatrix& mat1, const ScalarMatrix& mat2) {
        return ScalarMatrix(DiagonalMatrix(mat1) - DiagonalMatrix(mat2));
    }
    friend ScalarMatrix operator*(const ScalarMatrix& mat1, const ScalarMatrix& mat2) {
        return ScalarMatrix(DiagonalMatrix(mat1) * DiagonalMatrix(mat2));
    }
};


#endif //TD06_SCALARMATRIX_H
