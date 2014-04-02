#include "functions.h"
#include <iostream>
#include "math.h"

using namespace std;
Fraction convertToImproper (struct Fraction a);
Fraction proper (struct Fraction a);
Fraction summ (struct Fraction a, struct Fraction b);
Fraction defenition (struct Fraction a, struct Fraction b);
Fraction multiplication (struct Fraction a, struct Fraction b);
Fraction devision (struct Fraction a, struct Fraction b);

void menu (struct Fraction a, struct Fraction b)
{
    int enter;
    cout<<"Operations"<<endl;
    cout<<"For find summ press 1"<<endl;
    cout<<"For find definition press 2"<<endl;
    cout<<"For find multiplication press 3"<<endl;
    cout<<"For find devision press 4"<<endl;
    cin>>enter;
    if (enter=='1')
    {
        summ(a,b);
    }
    if (enter=='2')
    {
        defenition(a,b);
    }
    if (enter=='3')
    {
        multiplication(a,b);
    }
    if (enter=='4')
    {
        devision(a,b);
    }
}

void inputNumberF (struct Fraction a,struct Fraction b)
{
    cout<<"Enter the first number"<<endl;
    cout<<"   Integer part: ";
    cin>>a.integer;
    cout<<"   Numerator: ";
    cin>>a.numenator;
    cout<<"   Denominator (not 0): ";
    cin>>a.denominator;

    cout<<endl<<"Enter the second number"<<endl;
    cout<<"   Integer part: ";
    cin>>b.integer;
    cout<<"   Numerator: ";
    cin>>b.numenator;
    cout<<"   Denominator: ";
    cin>>b.denominator;
}

void outputNumber (struct Fraction a)
{
    {
        cout<<"   "<<a.integer<<" : "<<a.numenator<<" / "<<a.denominator<<endl;
    }
}

Fraction convertToImproper (struct Fraction a)
{
    if (a.numenator<0&&a.denominator<0&&a.integer>0)
    {
        a.numenator=fabs(a.numenator)+a.integer*fabs(a.denominator);
        a.denominator=fabs(a.denominator);
        a.integer=0;
    }
    if (a.numenator>0&&a.denominator<0&&a.integer>0)
    {
        a.numenator=(-1)*fabs(a.numenator)+fabs(a.denominator)*a.integer;
        a.denominator=fabs(a.denominator);
        a.integer=0;
    }
    if (a.numenator<0&&a.denominator>0&&a.integer>0)
    {
        a.numenator=(-1)*fabs(a.numenator)+fabs(a.denominator)*a.integer;
        a.denominator=a.denominator;
        a.integer=0;
        if (a.numenator>0&&a.denominator>0&&a.integer>0)
        {
            a.numenator=a.numenator+a.integer*a.denominator;
            a.denominator=a.denominator;
            a.integer=0;
        }
    }
    if (a.numenator<0&&a.denominator<0&&a.integer<0)
    {
        a.numenator=fabs(a.numenator)-fabs(a.integer)*fabs(a.denominator);
        a.denominator=fabs(a.denominator);
        a.integer=0;
    }
    if (a.numenator>0&&a.denominator<0&&a.integer<0)
    {
        a.numenator=(-1)*fabs(a.numenator)-fabs(a.denominator)*fabs(a.integer);
        a.denominator=fabs(a.denominator);
        a.integer=0;
    }
    if (a.numenator<0&&a.denominator>0&&a.integer<0)
    {
        a.numenator=(-1)*fabs(a.numenator)-fabs(a.denominator)*fabs(a.integer);
        a.denominator=a.denominator;
        a.integer=0;
    }
    if (a.numenator>0&&a.denominator>0&&a.integer<0)
    {
        a.numenator=a.numenator-fabs(a.integer)*a.denominator;
        a.denominator=a.denominator;
        a.integer=0;
    }
}

Fraction proper (struct Fraction a)
{
    if (fabs(a.numenator)>fabs(a.denominator)&&a.numenator>0)
    {
        a.integer=a.integer+a.numenator/a.denominator;
        a.numenator=a.numenator-a.denominator*(a.numenator/a.denominator);
        a.denominator=a.denominator;
    }
        if (fabs(a.numenator)>fabs(a.denominator)&&a.numenator<0)
    {
        a.integer=a.integer-fabs(a.numenator)/a.denominator;
        a.numenator=-fabs(a.numenator)+a.denominator*(fabs(a.numenator)/a.denominator);
        a.denominator=a.denominator;
    }
    if (fabs(a.numenator)==fabs(a.denominator)&&a.numenator>0)
    {
        a.integer=a.integer+1;
        a.numenator=0;
    }
    if (fabs(a.numenator)==fabs(a.denominator)&&a.numenator<0)
    {
        a.integer=a.integer-1;
        a.numenator=0;
    }
    int c;
    while (a.numenator%a.denominator)
    {
        c=a.numenator%a.denominator;
        a.numenator=a.denominator;
        a.denominator=c;
    }
    if (c!=1)
    {
        a.numenator/=c;
        a.denominator/=c;
    }
    return a;
}


Fraction summ (struct Fraction a, struct Fraction b)

{
    Fraction x,y;
    Fraction res;
    if (a.denominator!=0&&b.denominator!=0)
    {
        x=convertToImproper(a);
        y=convertToImproper(b);
    }
    if (x.numenator>0&&y.numenator>0)
    {
        res.numenator=(x.numenator)*(y.denominator)+(y.numenator)*(x.denominator);
        res.denominator=x.denominator*y.denominator;
    }
    if (x.numenator<0&&y.numenator<0)
    {
        res.numenator=(fabs(x.numenator)*(y.denominator)+fabs(y.numenator)*(x.denominator))*(-1);
        res.denominator=x.denominator*y.denominator;
    }
    if (x.numenator<0&&y.numenator>0)
    {
        res.numenator=(-1)*fabs(x.numenator)*(y.denominator)+(y.numenator)*(x.denominator);
        res.denominator=x.denominator*y.denominator;
    }
    if (x.numenator>0&&y.numenator<0)
    {
        res.numenator=(x.numenator)*(y.denominator)-fabs(y.numenator)*(x.denominator);
        res.denominator=x.denominator*y.denominator;
    }
    return   proper(res);
}

Fraction defenition (struct Fraction a, struct Fraction b)
{
    Fraction x,y;
    Fraction res;
    if (a.denominator!=0&&b.denominator!=0)
    {
        x=convertToImproper(a);
        y=convertToImproper(b);
    }
    if (x.numenator>0&&y.numenator>0)
    {
        res.numenator=(x.numenator)*(y.denominator)-(y.numenator)*(x.denominator);
        res.denominator=x.denominator*y.denominator;
    }
    if (x.numenator<0&&y.numenator<0)
    {
        res.numenator=-fabs(x.numenator)*(y.denominator)+fabs(y.numenator)*(x.denominator);
        res.denominator=x.denominator*y.denominator;
    }
    if (x.numenator<0&&y.numenator>0)
    {
        res.numenator=(-1)*fabs(x.numenator)*(y.denominator)-(y.numenator)*(x.denominator);
        res.denominator=x.denominator*y.denominator;
    }
    if (x.numenator>0&&y.numenator<0)
    {
        res.numenator=(x.numenator)*(y.denominator)+fabs(y.numenator)*(x.denominator);
        res.denominator=x.denominator*y.denominator;
    }
    return   proper(res);
}


Fraction multiplication (struct Fraction a, struct Fraction b)
{
    Fraction x,y;
    Fraction res;
    if (a.denominator!=0&&b.denominator!=0)
    {
        x=convertToImproper(a);
        y=convertToImproper(b);
    }
    if (x.numenator>0&&y.numenator>0)
    {
    res.numenator=(x.numenator)*(y.numenator);
    res.denominator=x.denominator*y.denominator;
    }
        if (x.numenator<0&&y.numenator<0)
    {
    res.numenator=fabs(x.numenator)*fabs(y.numenator);
    res.denominator=x.denominator*y.denominator;
    }
        if (x.numenator<0&&y.numenator>0)
    {
    res.numenator=(-1)*fabs(x.numenator)*(y.numenator);
    res.denominator=x.denominator*y.denominator;
    }
        if (x.numenator>0&&y.numenator<0)
    {
    res.numenator=(x.numenator)*fabs(y.numenator);
    res.denominator=x.denominator*y.denominator;
    }
    return   proper(res);
}

Fraction devision (struct Fraction a, struct Fraction b)
{
    Fraction x,y;
    Fraction res;
    if (a.denominator!=0&&b.denominator!=0)
    {
        x=convertToImproper(a);
        y=convertToImproper(b);
    }
    if (x.numenator>0&&y.numenator>0)
    {
    res.numenator=(x.numenator)*(y.denominator);
    res.denominator=x.denominator*y.numenator;
    }
        if (x.numenator<0&&y.numenator<0)
    {
    res.numenator=fabs(x.numenator)*fabs(y.denominator);
    res.denominator=x.denominator*y.numenator;
    }
        if (x.numenator<0&&y.numenator>0)
    {
    res.numenator=(-1)*fabs(x.numenator)*(y.denominator);
    res.denominator=x.denominator*y.numenator;
    }
        if (x.numenator>0&&y.numenator<0)
    {
    res.numenator=(-1)*(x.numenator)*(y.denominator);
    res.denominator=x.denominator*fabs(y.numenator);
    }
    return   proper(res);
}



