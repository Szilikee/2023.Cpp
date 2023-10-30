//
// Created by Szilikee on 2023. 10. 30..
//
#include "Matrix.h"
#include <random>

Matrix::Matrix(int mRows, int mCols) {
    this->mRows = mRows;
    this->mCols = mCols;
    this->mElements = new double*[mRows];
    for (int i = 0; i < mRows; i++) {
        this->mElements[i] = new double[mCols];
    }
}

Matrix::Matrix(const Matrix &what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = new double*[mRows];
    for (int i = 0; i < mRows; i++) {
        this->mElements[i] = new double[mCols];
        for (int j = 0; j < mCols; j++) {
            this->mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = what.mElements;
    what.mRows = 0;
    what.mCols = 0;
    what.mElements = nullptr;

}

Matrix::~Matrix() {
    for (int i = 0; i < mRows; i++) {
        delete[] this->mElements[i];
    }
    delete[] this->mElements;
    this->mRows = 0;
    this->mCols = 0;
    this->mElements = nullptr;
}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < mRows; i++) {
        for (int j = 0; j < mCols; j++) {
            this->mElements[i][j] = value;
        }
    }
}

void Matrix::randomMatrix(int a, int b) {
    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(a, b-1); // return a number in the given range
    for (int i = 0; i < mRows; i++) {
        for (int j = 0; j < mCols; j++) {
            this->mElements[i][j] = dist(mt);
        }
    }
}

void Matrix::printMatrix(ostream &os) const {
    for (int i = 0; i < mRows; i++) {
        for (int j = 0; j < mCols; j++) {
            os << this->mElements[i][j] << " ";
        }
        os << endl;
    }
}

bool Matrix::isSquare() const {
    return this->mRows == this->mCols;
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if (x.getRows() != y.getRows() || x.getCols() != y.getCols()) {
        throw std::out_of_range("Matrices must have the same dimensions");
    } else {
        Matrix *result = new Matrix(x.mRows, x.mCols);
        for (int i = 0; i < x.mRows; i++) {
            for (int j = 0; j < x.mCols; j++) {
                result->mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
            }
        }
        return *result;
    }
}

istream &operator>>(istream &is, Matrix &mat) {
    for (int i = 0; i < mat.mRows; i++) {
        for (int j = 0; j < mat.mCols; j++) {
            is >> mat.mElements[i][j];
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const Matrix &mat) {
    for (int i = 0; i < mat.mRows; i++) {
        for (int j = 0; j < mat.mCols; j++) {
            os << mat.mElements[i][j] << " ";
        }
    }
    return os;
}

double *Matrix::operator[](int index) {
    if(index < 0 || index >= this->mRows){
        throw std::out_of_range("Index doesn't exist");
    }
    return this->mElements[index];
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if (x.getCols() != y.getRows()) {
        throw std::out_of_range("Matrices must have the same dimensions");
    }
    Matrix *result = new Matrix(x.mRows, y.mCols);
    for (int i = 0; i < x.mRows; i++) {
        for (int j = 0; j < y.mCols; j++) {
            for (int k = 0; k < x.mCols; k++) {
                result->mElements[i][j] += x.mElements[i][k] * y.mElements[k][j];
            }
        }
    }
    return *result;
}

double *Matrix::operator[](int index) const {
    if(index < 0 || index >= this->mRows){
        throw std::out_of_range("Index out of range");
    }
    return this->mElements[index];
}

Matrix &Matrix::operator=(const Matrix &mat) {
    if(this->getRows() != mat.getRows() || this->getCols() != mat.getCols()){
        throw std::out_of_range("Matrices must have the same dimensions");
    }
    else
    {
        this->mRows = mat.mRows;
        this->mCols = mat.mCols;
        this->mElements = new double*[mRows];
        for (int i = 0; i < mRows; i++) {
            this->mElements[i] = new double[mCols];
            for (int j = 0; j < mCols; j++) {
                this->mElements[i][j] = mat.mElements[i][j];
            }
        }
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&mat) {
    this->mRows = mat.mRows;
    this->mCols = mat.mCols;
    this->mElements = mat.mElements;
    mat.mRows = 0;
    mat.mCols = 0;
    mat.mElements = nullptr;
    return *this;
}