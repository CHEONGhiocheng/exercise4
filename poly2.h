//
//  poly2.h
//  exercise4
//
//  Created by jane cheong  on 07/11/2022.
//

#ifndef poly2_h
#define poly2_h
#include <iostream>
#include <initializer_list>
class polynomial
{
public:
    polynomial();
    polynomial(int deg, double coef[]);
    polynomial(const polynomial & c); // copy constructor
    polynomial (polynomial && c); //move constructor
    polynomial(double const_term);
    ~polynomial();
    void print(std::ostream & out = std::cout) const;
    polynomial & operator= (const polynomial & c); // copy assignment
    polynomial & operator= (polynomial && c);//move assignment
    polynomial(std::initializer_list <int> list);   //constructor for a initializer list.
    polynomial & operator=(std::initializer_list<int> list); //assignment operator for initializer list.
    
private:
   int degree;
    double *coefficient;
};
std::ostream & operator<<(std::ostream & out, const polynomial &s);

#endif /* poly2_h */
