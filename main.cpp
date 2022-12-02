//
//  main.cpp
//  exercise4
//
//  Created by jane cheong  on 07/11/2022.
//

#include <iostream>
#include <initializer_list>
#include <iterator>
#include <algorithm>
#include "poly2.h"

polynomial::polynomial(){
    degree=1;
    coefficient=new double[1];
    coefficient[0] = 0.0;
}

 polynomial::polynomial(int k,double coef[]){
     degree = k;
     coefficient = new double[k];
    for (int i=0;i <= degree; i++){
    coefficient[i]=coef[i];
    }
}

polynomial::polynomial(double const_term){
    degree = 1;
    coefficient = new double [1];
    coefficient[0] = const_term;
}

polynomial::~polynomial(){
        delete [] coefficient;
}

void polynomial::print(std::ostream & out) const {
    if (degree == 0) {
        return;
    }
    for (int i = degree; i > 0; i--)
        out << coefficient[i] << "x^" << i << " + ";
    out << coefficient[0];
}
 
std::ostream & operator<<(std::ostream & out, const polynomial &s) {
    s.print(out);
    return out;
}

polynomial::polynomial(const polynomial & c){};
polynomial & polynomial::operator= (polynomial&& c){
    std :: cout << "Move assignment operator for String class got called." << std :: endl;
   if (this != &c)
         {
             degree = c.degree;
             coefficient = c.coefficient;
             c.degree = 0;
             c.coefficient = nullptr;
            }
            return (*this);
}

 polynomial::polynomial(std::initializer_list<int> list){
    list = {0};
    int n ;
    n = sizeof (list);
     if (n == 0){
         degree = 0;
     }
}

polynomial& polynomial::operator=(std::initializer_list <int> list){

    for (int i=0;i<= sizeof(list);i++){
        degree = i-1;
    }
     return (*this);
}

// initialization with initializer lists: std::vector <float > v= {1, 2, 3}, w= {7, 8, 9};

int main(int argc, const char * argv[]) {
    int list_degree;
    double coef[]={2,3,4,5};
    polynomial p1(3,coef);
    std::cout << "The polynomial p1 is " << p1 << std::endl;
    polynomial my_list {1,2,3,4};
    std::cout<< " The new size is \n" << sizeof(my_list) << std::endl;
    list_degree = sizeof(my_list)-1;
    std::cout<< " The new degree is \n"  << list_degree << std::endl;
    polynomial p2(list_degree, coef);
    std::cout << "The polynomial p2 is " << p2 << std::endl;
    return 0;
}
