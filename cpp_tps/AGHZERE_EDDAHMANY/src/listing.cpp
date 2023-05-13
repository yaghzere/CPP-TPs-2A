#include "matrix.h"



void foo(Matrix){

}

int main(int, char *[]){
    Matrix a, b, c;
    Matrix d = a * b;
    c = a * b;
    foo(c * c);
}