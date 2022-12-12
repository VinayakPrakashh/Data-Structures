#include<iostream>
using namespace std;
template<typename T>
T sum(T a,T b)
{
    return a+b;
}
int main()
{
    int a,b;
    float c,d;
    cout<<"Enter two integer numbers ";
    cin>>a>>b;
    cout<<endl<<"Enter two floating numbers ";
    cin>>c>>d;
     cout<<"Sum of Integer numbers - "<<sum(a,b)<<endl;
    cout<<"Sum of floating point numbers - "<<sum(c,d)<<endl;
}