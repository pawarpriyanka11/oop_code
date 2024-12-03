/*Create a C++ class named Television that has data members to hold the
model number and the screen size in inches, and the price. Member
functions include overloaded insertion and extraction operators. If more
than four digits are entered for the model, if the screen size is smaller
than 12 or greater than 70 inches, or if the price is negative or over $5000 then throw an integer. Write a main() function that instantiates a
television object, allows user to enter data and displays the data
members .If an exception is caught, replace all the data member values
with zero values.*/

#include<iostream>
using namespace std;
class television{
    public:
    int no,size,price;
    
    friend istream& operator>>(istream& in,television& t)
    {
        in>>t.no>>t.size>>t.price;
        if(t.no>9999)
        {
            throw 1;
        }
        if(t.size<12||t.size>70)
        {
            throw 2;
        }
        if(t.price<0||t.price>5000)
        {
            throw 3;
        }
    }
    friend ostream& operator<<(ostream& out,television& t)
    {
        
        out<<"\nModel number: "<<t.no<<"\nSize: "<<t.size<<"\nPrice: "<<t.price;
    }
    void reset()
    {
        no=0;
        size=0;
        price=0;
    }
};
int main()
{
    television t;
    try
    {  
        cout<<"\nEnter the model  number, size in inches and price of television: ";
        cin>>t;
        cout<<t;
    }
    catch(int i)
    {
        cout<<"\nException occur: "<<i;
        t.reset();
        cout<<t;

    }
    return 0;
}