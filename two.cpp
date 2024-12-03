/*A book shop maintains the inventory of books that are being sold at the
shop. 
The list includes details such as author, title, price, publisher and
stock position.
 Whenever a customer wants a book, the sales person
inputs the title and author and the system searches the list and displays
whether it is available or not.
 If it is not, an appropriate message is
displayed.
 If it is, then the system displays the book details and requests
for the number of copies required.
 If the requested copies book details
and requests for the number of copies required.
 If the requested copies
are available, the total cost of the requested copies is displayed; otherwise the message “Required copies not in stock” is displayed. 
Design a system using a class called books with suitable member
functions and Constructors. 
Use new operator in constructors to allocate
memory space required.
 Implement C++ program for the system.*/



#include<iostream>
using namespace std;
class book{
    public:
    string author, title, publisher;
    int price,stock;
    book()
    {
        title="";
        author="";
        publisher="";
        price=0;
        stock=0;
    }
    void accept()
    {
        cout<<"\nEnter the author,title,publisher,price,stock of the book: ";
        cin>>author>>title>>publisher>>price>>stock;

    }
    void display()
    {
        cout<<"\nAuthor\tTile\tPublis\tPrice\tStock"<<endl;
        cout<<author<<"\t"<<title<<"\t"<<publisher<<"\t"<<price<<"\t"<<stock;
    }
    void search(book b1[],int n)
    {
        int f=0,no;
        string t,a;
        cout<<"\nEnter the title: ";
        cin>>t;
        cout<<"\nEnter the author: ";
        cin>>a;

        for(int i=0;i<n;i++)
        {
            if(b1[i].title==t&&b1[i].author==a)
            {
                f=1;
                cout<<"\nBook availble!"<<endl;
                 b1[i].display();

                cout<<"\nEnter the number of copies you want to issue:";
                cin>>no;
                    
                if (no <= b1[i].stock) {
                    cout<<"\nTOtal cost of  book is: "<<b1[i].price*no;   
                    b1[i].stock -= no; // Update the stock after issuing the books
                } else {
                    cout << "\nRequired copies not in stock!" << endl;
                } 
                break;
                
            }
            
        }
        if(!f)
        {
            cout<<"\nRequired copies not in stock";
            
        }
    }
};
int main()
{
    int n,ch;
    book *b1;
  
    cout<<"\nEnter the number of records in library: ";
    cin>>n;
    b1=new book[n];

    do{
        cout<<"\nEnter your choice:\n1.Accept \n2. Display\n3.search\n4.exit"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
            for(int i=0;i<n;i++)
            {
                b1[i].accept();
            }
            break;

            case 2:
            for(int i=0;i<n;i++)
            {
                b1[i].display();
            }
            break;

            case 3:
            b1->search(b1,n);
            break;

            case 4:
            cout<<"\nExiting from the code!";
            break;

            default:
            cout<<"\nInvalid case!";

        }

    }while(ch!=4);
    return 0;
}