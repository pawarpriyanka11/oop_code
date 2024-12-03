/*Implement C++ program to implement a base class consisting of the
data members such as name of the student, roll number and subject.
The derived class consists of the data members subject code ,internal
assessment and university examination marks.
The program should have the facilities. i) Build a master table ii) List a table iii) Insert a
new entry iv) Delete old entry v) Edit an entry vi) Search for a record. Use virtual function*/

#include<iostream>
#include<iomanip>
using namespace std;
class student{
    public:
    string name,*sub;
    int roll;
    
    virtual void accept(int n)
    {
        cout<<"\nEnter roll:";
        cin>>roll;
        cout<<"\nEnter name: ";
        cin>>name;
        cout<<"\nEnter subjects: ";

        sub=new string[n];
        for(int i=0;i<n;i++)
        {   cout<<"subject"<<i+1<<": ";
            cin>>sub[i];
        }

    }


    virtual void display(int n)
    {

        cout<<left<<setw(10)<<"roll no"<<setw(15)<<"name"<<"subjcet\n";
        cout<<setw(10)<<roll<<setw(15)<<name;
        for(int i=0;i<n;i++)
        {
            cout<<sub[i]<<" ";
        }
        cout<<endl
        
        
    }

    virtual ~student()
    {
    delete[] sub;
    }
};
class academics:public student{
    public:
    string subcode;
    int *internal,*external,*total;

    void accept(int n)
    {
        student::accept(n);
        internal=new int[n];
        external=new int[n];

        for(int i=0;i<n;i++)
        {
            cout<<"\nEnter internal marks for "<<sub[i]<<": ";
            cin>>internal[i];
            cout<<"\nEnter external marks for "<<sub[i]<<": ";
            cin>>external[i];
        }

        cout<<"\nEnter total: ";
        cin>>total;
        cout<<"\nPercentage="<<((internal+external)/total)*100;
    }

    void display(int n)
    {
        cout<<"\ninternal"<<iternal<<"external"<<external<<endl;

    }

    // void calculate(int internal,int external)
    // {
    //     int total;
    //     cout<<"\nEnter total marks internal+extrenal: ";
    //     cin>>total;
    //     cout<<"\nPercentage:"<<((internal+external)/total)*100;
    // }

};
int main()
{
    student s,*bptr;
    academics a;


    int ch,n;
    cout<<"\nEnter the number of subjects:";
    cin>>n;
    do{
        cout<<"\nEnter your choice:\ni) Build a master table \nii) List a table \niii) Insert a
new entry \niv) Delete old entry \nv) Edit an entry \nvi) Search for a record. \n";
cin>>ch;
switch(ch)
{
    case 1:
    bptr=&a;
    bptr->accept(n);
    bptr=&s;
    bptr->accept(n);
    break;

    case 2:
    break;

    case 3:
    break;

    case 4:
    break;

    case 5:
    break;

    case 6:
    break;

    case 7:
    cout<<"\nExiting from the code!";
    return 0;
    break;

    default:
    cout<<"\nInvalid case!";

}
    }while(ch!=7);
    return 0;


}