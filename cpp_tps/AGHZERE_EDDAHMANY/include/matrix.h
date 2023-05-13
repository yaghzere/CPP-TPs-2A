#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string.h>
#include <cmath>
class Matrix{
private:
    double * _array;
    int _nrow, _ncol;

public:
    Matrix();
    Matrix(int, int);
    Matrix(int, int, double[]);
    Matrix(const Matrix &);
    Matrix(Matrix &&);
    ~Matrix();
    void display() const;
    Matrix & operator=(const Matrix & );
    Matrix & operator=(Matrix && );
    double * operator[](int );
    double operator()(int , int ) const;
    friend Matrix operator+(const Matrix & , const Matrix & );
    friend Matrix operator-(const Matrix & , const Matrix & );
    friend Matrix operator-(const Matrix & );
    friend Matrix operator*(const Matrix & , const Matrix & );
    friend std::ostream & operator<<(std::ostream &, const Matrix & );
    friend std::istream & operator>>(std::istream &, const Matrix & );
    friend bool is_square(const Matrix &);
    friend Matrix transpose(const Matrix & );
    friend Matrix identity_matrix(int);
    bool isNull(double) const;
    friend Matrix inverse_of_matrix(const Matrix &, int, double);

};

Matrix identity_matrix(int);
Matrix inverse_of_matrix(const Matrix &, int, double);



#endif //MATRIX_H

