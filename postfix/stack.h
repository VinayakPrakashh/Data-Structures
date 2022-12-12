#include <iostream>

using namespace std;

template <class T> class stack
{
    T arr[10];
    int top,max;
    public:
        stack();
        void push(T);
        T pop();
        int isEmpty();
        int isFull();
        void disp();
};
template <class T> stack<T>::stack()
{
    top=-1;
    max=5;
}
template <class T>int stack<T>::isFull()
{
    if (top==max-1)
        return 1;
    else
        return 0;
}
template <class T> int stack<T>::isEmpty()
{
    if (top==-1)
        return 1;
    else
        return 0;
}
template <class T> void stack<T>::push(T ele)
{
    if (!isFull())
    {
        top++;
        arr[top]=ele;
    }
    else
        cout<<"Stack is full ";
}
template <class T>T stack<T>::pop()
{
    T retvalue;
    if (!isEmpty())
    {
        retvalue=arr[top];
        top--;
    }
    else
        cout<<"Stack is empty ";
    return retvalue;
}
template <class T> void stack<T>::disp()
{
    for(int i=top;i>=0;i--)
        cout<<arr[i]<<" ";
}