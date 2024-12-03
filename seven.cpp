/*Write a function template selection Sort. Write a program that inputs, sorts and outputs an integer array and a float array.*/

#include<iostream>
using namespace std;
template <typename t1>
void sort(t1 a[], int size)
{
    int min;

    for(int i=0;i<size;i++)
    {
        min=i;
        for(int j=i+1;j<size;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            t1 temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    
}
int main()
{

 
    int a[5],size;
    cout<<"\nEnter the array elemnts: ";
    for(int i=0;i<5;i++)
    {
        cin>>a[i];

    }
    sort(a,5);

    float a1[5];
     cout<<"\nEnter the array elemnts: ";
    for(int i=0;i<5;i++)
    {
        cin>>a1[i];

    }
    sort(a1,5);


    return 0;
}