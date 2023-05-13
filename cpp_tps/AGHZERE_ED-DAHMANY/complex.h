#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

#define DEBUG_ENABLE 1

class Complex {
private:
    double _re, _im;
public:
    Complex(){
        _re = _im = 0.0;
        if(DEBUG_ENABLE){
            std::cout << "+++Complex()" << std::endl;
            std::cout << this << "\n" << std::endl;
        }
    }

    Complex(double re, double im){
        _re = re;
        _im = im;
        if(DEBUG_ENABLE){
            std::cout << "+++Complex(" << _re << "," << _im << ")" << std::endl;
            std::cout << this << "\n" << std::endl;
        }
    }

    Complex(const Complex & z){
        _re = z._re;
        _im = z._im;
        if(DEBUG_ENABLE){
            std::cout << "rrrComplex(" << z._re << "+i." << z._im << ")" << std::endl;
            std::cout << &z << "\n" << std::endl;
        }
    }

    Complex & operator=(const Complex & z){
        if(DEBUG_ENABLE){
            std::cout << "op=Complex(" << z._re << "+i." << z._im << ")" << std::endl;
            std::cout << this << "\n" << std::endl;
        }
        if (this == &z){
            return *this;
        }
        _re = z._re;
        _im = z._im;
        return *this;
    }

    double getRe() const{
        return _re;
    }

    double getIm() const{
        return _im;
    }

    void setRe(double re){
        _re = re;
    }

    void setIm(double im){
        _im = im;
    }

    double modulus() const{
        return sqrt(_re * _re + _im * _im);
    }

    double argument() const{
        if(_re == 0){
            if(_im == 0){
                return 0;
            }
            else if(_im < 0){
                return - M_PI / 2;
            }
            else {
                return M_PI / 2;
            }
        }
        return atan(_im / _re);
    }

    void display() const{
        std::cout << _re << "+i." << _im << std::endl;
    }

    void swapReIm(){
        double tmp = _re;
        _re = _im;
        _im = tmp;
    }

    void deleteComplex(){
        if(DEBUG_ENABLE){
            std::cout << "---Complex(" << this->_re << "," << this->_im << ")" << std::endl;
            std::cout << this << "\n" << std::endl;
        }
        delete this;
    }
    

};


Complex sum(const Complex z1, const Complex z2){
    Complex res(z1.getRe() + z2.getRe(), z1.getIm() + z2.getIm());
    return res;
}

Complex multiplication(const Complex z1, const Complex z2){
    Complex res(z1.getRe() * z2.getRe() - z1.getIm() * z2.getIm(), z2.getRe() * z1.getIm() + z1.getRe() * z2.getIm());
    return res;
}

Complex substraction(const Complex z1, const Complex z2){
    Complex res(z1.getRe() - z2.getRe(), z1.getIm() - z2.getIm());
    return res;
}

Complex operator+(const Complex & z1, const Complex & z2){
    Complex res(z1.getRe() + z2.getRe(), z1.getIm() + z2.getIm());
    return res;
}

Complex operator*(const Complex & z1, const Complex & z2){
    Complex res(z1.getRe() * z2.getRe() - z1.getIm() * z2.getIm(), z2.getRe() * z1.getIm() + z1.getRe() * z2.getIm());
    return res;
}

Complex operator-(const Complex & z1, const Complex & z2){
    Complex res(z1.getRe() - z2.getRe(), z1.getIm() - z2.getIm());
    return res;
}

Complex normalized(const Complex z) {
    Complex res(z.getRe() / z.modulus(), z.getIm() / z.modulus());
    return res;
}

void rotate(Complex & z, double tetha){
    z.setRe(z.modulus() * z.getRe() * cos(tetha));
    z.setIm(z.modulus() * z.getIm() * sin(tetha));
}

const Complex & maxModulus(const Complex & z1, const Complex & z2){
    if(z1.modulus() < z2.modulus()){
        return z2;
    }
    return z1;
}

void rootsOfUnity(int size, Complex roots[]){
    for(int i = 0; i < size; i++){
        roots[i] = Complex(cos(2 * i * M_PI / size), sin(2 * i * M_PI / size));
    }
    return;
}



#endif //COMPLEX_H