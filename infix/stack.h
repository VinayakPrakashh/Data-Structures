#include<iostream>
using namespace std;
template<class T>
class stack
{
   
    public:
     T arr[10],i,max=5,ret;
    int top;
    stack();
    void push(T);
    void list(T);
    T pop();
    int isfull();
    int isempty();
    T topstack();

};
template<class T>stack<T>::stack()
{
    top=-1;
}
template<class T>int stack<T>::isfull()
{
    if(top==max-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
template<class T>int stack<T>::isempty()
{
    if(top==-1)
    {
        return 1;
    
}
else
{
    return 0;
}
}
template<class T> void stack<T>::push(T ret)
{
    if(isfull()==0){
    top++;
    arr[top]=ret;
    }
    else{
        cout<<"stack is full\n";
    }
}
template<class T>T stack<T>::pop()
{
    if(!isempty()){
    T ret;
    arr[top]=ret;
    top--;
}
     else
        {
            cout<<"stack is empty\n";
            return ret;
            
        }
}
template <class T>void stack<T>::list(T element)
{
    for(i=top;i>=0;i--)
    {
        cout<<arr[i]<<" ";
    }
}
template <class T>T stack<T>::topstack()
{
    return arr[top];
}