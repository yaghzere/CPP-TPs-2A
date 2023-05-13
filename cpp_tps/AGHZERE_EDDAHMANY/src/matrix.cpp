#include "matrix.h"
#define DEBUG_ENABLE 0
#define DEBUG_ENABLE_LISTING1 1
using namespace std;


Matrix::Matrix(){
    _nrow = 0;
    _ncol = 0;
    _array = nullptr;
    if(DEBUG_ENABLE){
        cout << "+++Matrix()" << endl;
        cout << this << "\n" << endl;
    }
}

Matrix::Matrix(int nrow, int ncol){
    _nrow = nrow;
    _ncol = ncol;
    _array = new double[nrow * ncol];
    if(DEBUG_ENABLE){
        cout << "+++Matrix(" << _nrow << "," << _ncol << ")" << endl;
        cout << this << "\n" << endl;
    }
}

Matrix::Matrix(int nrow, int ncol, double table[]){
    _nrow = nrow;
    _ncol = ncol;
    _array = new double[nrow * ncol];
    // for(int i = 0; i < nrow * ncol; i++){
    //     _array[i] = table[i];
    // }
    memcpy(_array, table, nrow * ncol * sizeof(double));
    if(DEBUG_ENABLE){
        cout << "+++Matrix(" << _nrow << "," << _ncol << ", table " << ")" << endl;
        cout << this << "\n" << endl;
    }
}

Matrix::Matrix(const Matrix & M){
    // _array = M._array;
    _nrow = M._nrow;
    _ncol = M._ncol;
    _array = new double[_nrow * _ncol];
    memcpy(_array, M._array, _nrow * _ncol * sizeof(double));
    
    if(DEBUG_ENABLE){
        cout << "rrrMatrix(" << M._nrow << "," << M._ncol << ")" << endl;
        cout << &M << "\n" << endl;
    }
}

Matrix::~Matrix(){
    if(DEBUG_ENABLE){
        cout << "---Matrix(" << _nrow << "," << _ncol << ")" << endl;
        cout << this << "\n" << endl;
    }
}

Matrix::Matrix(Matrix && M){
    if(DEBUG_ENABLE || DEBUG_ENABLE_LISTING1){
        cout << "depMatrix(" << M._nrow << "," << M._ncol << ")" << endl;
        cout << &M << "\n" << endl;
    }
    _array = M._array;
    _nrow = M._nrow;
    _ncol = M._ncol;
    M._ncol = M._nrow = 0;
    M._array = nullptr;
}

void Matrix::display() const{
    cout << "[";
    for(int i = 0; i < _nrow; i++){
        cout << "[";
        for(int j = 0; j < _ncol; j++){
            cout << _array[i * _nrow + j]; 
            if(j != _ncol - 1){
                cout << ", ";
            }
        }
        cout << "]";
        if(i != _nrow - 1){
                cout << ", ";
        }
    }
    cout << "]\n" << endl;
}


Matrix & Matrix::operator=(const Matrix & M){
    if(DEBUG_ENABLE){
        cout << "op=Matrix(" << _nrow << "," << _ncol << ")" << endl;
        cout << this << "\n" << endl;
    }
    if(this == &M){
        return *this;
    }
    delete[] _array;
    _nrow = M._nrow;
    _ncol = M._ncol;
    _array = new double[_nrow * _ncol];
    memcpy(_array, M._array , _nrow * _ncol * sizeof(double));
    return *this;
}


Matrix & Matrix::operator=(Matrix && M){
    if(DEBUG_ENABLE || DEBUG_ENABLE_LISTING1){
        cout << "opdMatrix(" << _nrow << "," << _ncol << ")" << endl; // opd : op dep
        cout << this << "\n" << endl;
    }
    if(this == &M){
        return *this;
    }
    delete[] _array; //just added
    _nrow = M._nrow;
    _ncol = M._ncol;
    _array = M._array;
    M._array = nullptr;
    M._nrow = M._ncol = 0;
    return *this;
}


double * Matrix::operator[](int n){
    if(DEBUG_ENABLE){
        cout << "op[]Matrix" << endl; // opd : op dep
        cout << this << "\n" << endl;
    }
    return (_array + n * _ncol);

}

/*

Rule broken : Encapsulation ==> The fact of calling an element by m[i][j] allows in a first time 
(as soon as m[i] is called) to return a pointer to an element of the array representing the matrix m, and thus to have 
a pointer to a PRIVATE attribute. Although we have access to elements that we should not normally have access to, like
for example asking for the value m[i][-1]

In this sense, the alternative operator below allows to avoid these problems.
*/

//alternative

double Matrix::operator()(int row, int col) const{
    if(DEBUG_ENABLE){
        cout << "op(" << row << "," << col << ")Matrix" << endl; // opd : op dep
        cout << this << "\n" << endl;
    }
    if (row > _nrow || row <= 0 || col > _ncol || col <= 0){
        cout << "Index out of bound" << endl;
        return -999;
    }

    // cout << "Do you want to get (THEN ANSWER o) this value or set another double on it (THEN ENTER THE NEW VALUE)?\n" << endl;
    // double decision;
    // cin >> decision;
    // if (decision == 'o'){
    //     return _array[(row - 1) * _ncol + col - 1];
    // } 
    // else{
    //     _array[(row - 1) * _ncol + col - 1] = decision;
    //     return 1;
    // }

    return _array[(row - 1) * _ncol + col - 1];

}



Matrix operator+(const Matrix & m1, const Matrix & m2){
    Matrix res(m1);
    for(int i = 0; i < m1._nrow * m1._ncol; i++){
        res._array[i] += m2._array[i];
    }
    return res;
}

Matrix operator-(const Matrix & m1, const Matrix & m2){
    if(DEBUG_ENABLE){
        cout << "op-bMatrix" << endl;
    }
    Matrix res(m1);
    try{
        for(int i = 0; i < m1._nrow * m1._ncol; i++){
            res._array[i] -= m2._array[i];
        }
    } catch(char * e){
        perror("Index out of bound\n");
        exit(EXIT_FAILURE);
    }
    return res;
}


Matrix operator-(const Matrix & m1){
    if(DEBUG_ENABLE){
        cout << "op-u" << "Matrix" << endl; 
    }
    Matrix res(m1);
    for(int i = 0; i < m1._nrow * m1._ncol; i++){
        res._array[i] *= -1;
    }
    return res;
}

Matrix operator*( const Matrix & m1, const Matrix & m2){
    if(DEBUG_ENABLE){
        cout << "op*" << "Matrix" << endl;
    }
    try{
        Matrix res(m1._nrow, m2._ncol);
        double coef;
        for(int row = 1; row <= m1._nrow; row++){
            for(int col = 1; col <= m2._ncol; col++){
                coef = 0;
                int i = 1, j = 1;
                while(i <= m2._nrow && j <= m1._ncol){
                    coef = coef + m1(row,j) * m2(i, col);
                    i++;
                    j++;
                }
                res._array[(row - 1) * m1._ncol + col - 1] = coef;
            }
        }
        return res;
    }catch(char * e){
        perror("Index out of bound\n");
        exit(EXIT_FAILURE);
    }
    
}


ostream & operator<<(ostream & out, const Matrix & m){
    out << '[';
    for(int i = 0; i < m._nrow; i++){
        out << '[';
        for(int j = 0; j < m._ncol; j++){
            out <<  m._array[i * m._nrow + j];
            if(j != m._ncol - 1){
                out << ',';
                out <<  ' ';
            }
        }
        out << ']';
        if(i != m._nrow - 1){
                out << ',';
                out << ' ';
        }
    }
    out << ']';
    out << '\n';
    return out;
}

istream & operator>>(istream & in, const Matrix & m){
    for(int i = 0; i < m._nrow * m._ncol; i++){
        in >> m._array[i];
    }
    return in;
}



bool is_square(const Matrix & m) {
    return (m._nrow == m._ncol);
}

Matrix transpose(const Matrix & m){
    Matrix res(m._ncol, m._nrow);
    double coef;
    for(int i = 1; i <= m._nrow; i++){
        for(int j = 1; j <= m._ncol; j++){
            coef = m(i, j);
            // cout << coef << endl;
            res._array[(i - 1) * m._ncol + j - 1] = m(j, i);
            res._array[(j - 1) * m._ncol + i - 1] = coef;
        }
    }
    return res;
}


Matrix identity_matrix(int size){
    Matrix res(size, size);
    double tmp = 0.0;
    for (int i = 1; i <= size; i++){
        for (int j = 1; j <= size; j++){
            if(i != j){
                tmp = 1.0;
            }
            res._array[(i - 1) * res._ncol + i - 1] = tmp;
        }
    }
    return res;
}

/****************************Partie alternative******************************/

bool Matrix::isNull(double epsilon) const{
    for(int i = 0; i < _nrow * _ncol; i++){
        if(abs(_array[i]) >= epsilon){
            return false;
        }
    }
    return true;
}


Matrix inverse_of_matrix(const Matrix & M, int n, double epsilon){
    Matrix A = identity_matrix(M._nrow) - M;
    // cout << "M = " << endl;
    // cout << M << endl;
    Matrix sum_Ak(M._nrow, M._ncol);
    Matrix inverse_of_M(M._nrow, M._ncol);
    int i = 0;
    while(i <= n && !(A.isNull(epsilon))){
        printf("i = %d\n", i);
        
        sum_Ak = sum_Ak + A;
        A = A * A;
        i++;
    }
    if(i == n){
        printf("Ak not null, then M not inversible\n");
        exit(EXIT_FAILURE);
    }
    else{
        try{
            return sum_Ak;
        }catch(char * e){
            perror("Inversion impossible");
            exit(EXIT_FAILURE);
        }
    }
}
