#include<iostream>
using namespace std;
template<class T>
class stack
{
   
    public:
     T arr[10],i,max=2;
    int top;
    stack();
    void push(T);
    void list(T);
    T pop();
    int isfull();
    int isempty();

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
template<class T> void stack<T>::push(T element)
{
    if(isfull()==0){
         cout<<"Enter the element to push ";
        cin>>element;
    top++;
    arr[top]=element;
    }
    else{
        cout<<"stack is full\n";
    }
}
template<class T>T stack<T>::pop()
{
    if(!isempty()){
    cout<<"POP element is ";
    T element;
    arr[top]=element;
    top--;
    return element;
   
}
     else
        {
            cout<<"stack is empty\n";
            
        }
}
template<class T>void stack<T>::list(T element)
{
    for(i=top;i>=0;i--)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    stack<int> s;
    int ch=1,element;
    while(ch!=4)
    {
        cout<<"1.PUSH\n2.POP\n3.LIST\n4.EXIT\n";
        cout<<"Enter the choice ";
        cin>>ch;
    
    switch(ch){
        case 1 :
        s.isfull();
        s.push(element);
        break;
        case 2 :
    s.isempty();
      s.pop();
      int ele;
      ele=s.pop();
      cout<<ele<<endl;
      
   
        
      break;
        
        case 3 : cout<<"Elements in the stack -\n";
        s.list(element);
        break;
    } 
    }
    }