/*Define a class to represent a bank account which includes the following
members as:
a. Name of the depositor
b. Account Number
c. Withdrawal amount
d. Balance amount in the account
Member Functions:
e. To assign initial values
f. To deposit an amount
g. To withdraw an amount after checking the balance
h. To display name and balance. Implement the program by using features of OOP in C++*/




#include<iostream>
using namespace std;
class bank{
    public:
    string name;
    int withdraw_amt,deposit_amt,acc_no,balance_amt;

    void initalize()
    {
        cout<<"\nEnter the name of depositer: ";
        cin>>name;
        cout<<"\nEnter the account number: ";
        cin>>acc_no;
        cout<<"\nEnter the inital balance amount: ";
        cin>>balance_amt;   
    }

    void deposite()
    {
        cout<<"\nEnter the amount to be deposited:";
        cin>>deposit_amt;
        if(deposit_amt<0)
        {
            cout<<"\nInvalid input!";

        }
        else
        {
            balance_amt+=deposit_amt;
            cout<<"\nAmount has been deposited sucessfully!";
            cout<<"\nUpdated balance amount is: "<<balance_amt;
        }
    }

    void withdraw()
    {
        cout<<"\nEnter the amount to be withdraw: ";
        cin>>withdraw_amt;
        if(withdraw_amt>balance_amt)
        {
            cout<<"\nAmount to be withdraw is greater than available balance in account!";
        }
        else{
            balance_amt-=withdraw_amt;
            cout<<"\nAmount withdrawn sucessfully!";
            cout<<"\nNew updated balance is: "<<balance_amt;
        }
    }

};
int main()
{
    bank b1;
    b1.initalize();
    b1.deposite();
    b1.withdraw();
    return 0;

}