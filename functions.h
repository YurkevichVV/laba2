#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct Fraction
{
    int integer;
    int numenator;
    int denominator;
};

void menu (struct Fraction a, struct Fraction b);
void outputNumber (struct Fraction a);
void inputNumber (struct Fraction a,struct Fraction b);


#endif
