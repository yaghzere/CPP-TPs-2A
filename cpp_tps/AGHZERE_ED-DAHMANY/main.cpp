#include <complex.h>
using namespace std;

int main(){

    //Constructors
    Complex z1;
    cout << "z1 = ";
    z1.display();
    Complex z2(1.0, 1.0);
    cout << "z2 = ";
    z2.display();
    Complex z3(z2);
    cout << "z3 = ";
    z3.display();

    //Modulus, argument
    cout << "mod(z1) = " << z1.modulus() << endl;
    cout << "mod(z2) = " << z2.modulus() << endl;
    
    cout << "arg(z1) = " << z1.argument() << endl;
    cout << "arg(z2) = " << z2.argument() << endl;

    //Swap
    Complex z4(2.0, 1.0);
    cout << "z4 before swap" << endl;
    cout << "z4 = ";
    z4.display();
    z4.swapReIm();
    cout << "z4 after swap" << endl;
    cout << "z4 = ";
    z4.display();

    //Sum
    Complex z5;
    z5 = sum(z3, z4);
    cout << "z5 = sum(z3, z4) = ";
    z5.display();

    //Multiplication
    Complex z6;
    z6 = multiplication(z3, z4);
    cout << "z6 = multiplication(z3, z4) = ";
    z6.display();

    //Substraction
    Complex z7;
    z7 = substraction(z3, z4);
    cout << "z7 = substraction(z3, z4) = ";
    z7.display();

    /*2. Erreur de compilation si on essaie d'utiliser les variables _re et _im des variables.
     C'est à cause de l'encapsulation*/

    //operators + * -
    Complex z8, z9, z10;
    z8 = z3 + z4;
    cout << "z8 = z3 + z4 = ";
    z8.display();

    z9 = z3 - z4;
    cout << "z9 = z3 - z4 = ";
    z9.display();

    z10 = z3 * z4;
    cout << "z10 = z3 * z4 = ";
    z10.display();

    /*4. From a mathematical point of vue, it's possible because if z is a complex then there is one and only
     one couple (r, tetha) for which z = r * exp(i* thetha)
     But from a computer point of vue, it's not possible because we already defined a constructor that takes
      two doubles as arguments so it will be ambiguous*/

    /*5. There is to ways. The first one is to convert double to complex but it's not effiient 
    because of te fact that we need to allocate a memory space to the imaginary part
    of the double with no benefits. The second one is to overload operators but this time with complex as first argument,
     and double for the second one*/

    //Normalized
    Complex z11 = normalized(z10);
    cout << "z11 = normalized(z10) = ";
    z11.display();

    //Rotate
    rotate(z11, M_PI / 2);
    cout << "rotate(z11, PI / 2) = ";
    z11.display();

    //Max Modulus
    Complex z12 = maxModulus(z11, z11 * z11);
    cout << "z12 = maxModulus(z11, z11 * z11) = ";
    z12.display();

    //Roots of unity
    const int size = 12;
    static Complex roots[size];
    rootsOfUnity(size, roots);
    for(int i = 0; i < size; i++){
        cout << "roots[" << i << "] = ";
        roots[i].display();
    }

}