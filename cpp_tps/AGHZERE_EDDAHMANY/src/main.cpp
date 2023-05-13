#include "matrix.h"
using namespace std;

int main(){

    //Constructors

    Matrix m1; 
    Matrix m2(3, 4);
    double table[9] = {1.7,1.0,1.0,2.5,2.0,2.0,3.0,3.0,3.5};
    Matrix m3(3, 3, table);
    Matrix m4(m3);

    //Display

    m2.display();
    m3.display();
    m4.display();

    //Assignment operator

    Matrix m5;
    m5 = m4;
    m5.display();

    //Move Constructor
    
    Matrix m6 = std::move(m5);
    m6.display();

    //Move assignment operator

    //[] Operator
    int dim_m4 = 3;
    double * m_row = new double[dim_m4];
    m_row = m4[1];
    for(int i = 0; i < 3; i++){
        printf("m4[%d][%d] = %f\n", 1, i, m_row[i]);
    }
    for(int i = 0; i < 3; i++){
        printf("m4[%d][%d] = %f\n", 1, i, m4[1][i]);
    }

    //(i, j) operator

    cout << "m4(1,1) = " << m4(1,1) << endl;
    cout << "m4(3,3) = " << m4(3,3) << endl;
    cout << "m4(2,1) = " << m4(2,1) << endl;
    cout << "m4(3,4) = " << m4(3,4) << endl;

    //operator+ operator - (binary op)
    Matrix m7, m8;
    m7 = m3 + m4;
    m8 = m3 - m4;
    m7.display();
    m8.display();

    //operator - (unaire)
    Matrix m9;
    m9 = -m4;
    m9.display();


    //operator * 
    Matrix m10;
    m10 = m3 * m4;
    m10.display();

    //operator <<
    cout << m10;

    //operator >>
    int m11_row = 2;
    int m11_col = 2;
    Matrix m11(m11_row, m11_col);
    cout << "Please enter the matrix coeficients line per line: (rows, cols) = (" << m11_row << "," << m11_col << ")" << endl;
    cin >> m11;
    m11.display();


    //Matrix is square
    Matrix m12(4, 5);
    cout << is_square(m10) << endl;
    cout << is_square(m12) << endl;

    //Transpose
    Matrix m13;
    m13 = transpose(m10);
    m13.display();

    //Id matrix
    Matrix I;
    int size = 5;
    I = identity_matrix(size);
    I.display();

/****************************Partie alternative******************************/


    //isNULL()
    double parameter = 0.3; // You can change this value to 0.1 and you will get 0 instead of 1
    double table1[9] = {parameter,0.1,0.0,0.1,0.1,0.1,0.0,0.0,0.1};
    float epsilon = 0.2;
    Matrix m14(3, 3, table1);
    cout << m14.isNull(epsilon) << endl;   

    //Inverse of matrix
    Matrix inv =  inverse_of_matrix(I, 20, 0.1); 
    inv.display();
    cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
    double table2[9] = {5.0/10.0, -1.0/4.0, -1.0/8.0, -5.0/7.0, 1.0, -2.0/10.0, -3.0/10.0, -3.0/8.0, 8.0/10.0};
    // double table2[9] = {0.5, 0.5, 0.3, 0.1, 0.4, 0.4, 0.3, 0.3, 0.3};

    Matrix matrix_test(3, 3, table2);
    Matrix inv_test = inverse_of_matrix(matrix_test, 2000000, 1e-50);
    cout << "matrix_test = ";
    cout << matrix_test << endl;
    cout << "inv_test = ";
    cout << inv_test << endl;
    Matrix matrix_test_multiplied_by_inv_test = inv_test * matrix_test;
    cout << "matrix_test_multiplied_by_inv_test = ";
    cout << matrix_test_multiplied_by_inv_test << endl;
 
    
    

    return 0;
}