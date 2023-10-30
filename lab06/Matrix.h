//
// Created by Szilikee on 2023. 10. 30..
//

#ifndef MAIN_06_CPP_MATRIX_H
#define MAIN_06_CPP_MATRIX_H

#include <iostream>
#include <stdexcept>


using namespace std;
class Matrix {
public:

    Matrix(int mRows = 10, int mCols = 10);

    void fillMatrix(double value);

    ~Matrix();

    Matrix(Matrix &&what);

    void printMatrix(ostream& os = cout) const;

    Matrix(const Matrix &what);

    int getRows() const { return this->mRows;}

    int getCols() const { return this->mCols;}

    Matrix & operator=(const Matrix &mat);

    Matrix& operator=(Matrix&& mat);

    double* operator[] (int index);

private:
    double **mElements;
    int mRows; //number of rows
    int mCols; //number of columns

    void randomMatrix(int a, int b);

    bool isSquare() const;

    friend Matrix operator+(const Matrix& x, const Matrix& y);
    friend Matrix operator*(const Matrix& x, const Matrix& y);
    friend istream & operator>>(istream& is, Matrix& mat);
    friend ostream & operator<<(ostream& os, const Matrix& mat);

    double* operator[] (int index) const;

};


#endif //MAIN_06_CPP_MATRIX_H
