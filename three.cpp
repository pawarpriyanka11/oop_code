/*Design a C++ Class ‘Complex ‘ with data members for real and
imaginary part. Provide default and parameterized constructors. Write a
program to perform arithmetic operations of two complex numbers
using operator overloading (using either member functions or friend
functions).*/


//member function has been used

#include<iostream>
using namespace std;
class complex
{
    public:
    int r,i;

    complex()
    {
        r=0;
        i=0;

    }
    complex(int r1,int i1)
    {
        r=r1;
        i=i1;
    }

    void display()
    {
        cout<<r<<"+"<<i<<"i";
    }

    complex operator+(complex& c);
    complex operator-(complex& c);
    complex operator*(complex& c);
    complex operator/(complex& c);
};
complex complex::operator+(complex& c)
{
    return complex(r+c.r,i+c.i);
}
complex complex::operator-(complex& c)
{
    return complex(r-c.r,i-c.i);
}

complex complex::operator*(complex& c)
{
    int real=(r*c.r)-(i*c.i);
    int img=(r*c.i)+(i*c.r);
    return complex(real,img);
}

complex complex::operator/(complex& c)
{
    int denominator=(c.r*c.r)+(c.i*c.i);
    if(denominator==0)
    {
       cout<<"\nDivision by zero is undefined!";
       
    }
    int real=(r*c.r+i*c.i)/denominator;
    int img=(i*c.r-r*c.i)/denominator;
    return complex(real,img);
    
}
int main()
{
    int r1,i1;
    cout<<"\nEnter the value of real part: ";
    cin>>r1;
    cout<<"\nEnter the value of img part: ";
    cin>>i1;
    complex c1(r1,i1);

    cout<<"\nEnter the value of real part: ";
    cin>>r1;
    cout<<"\nEnter the value of img part: ";
    cin>>i1;
    complex c2(r1,i1);

    complex sum=c1+c2;
    complex sub=c1-c2;
    complex mul=c1*c2;
    complex div=c1/c2;


    cout<<"\nADDITION:";
    sum.display();
    cout<<"\nSUBTRACTION:";
    sub.display();
    cout<<"\nMULTIPLICATION:";
    mul.display();
    cout<<"\nDIVISION:";
    div.display();


    return 0;
}