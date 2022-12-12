#include<iostream>
using namespace std;
template <class T>class queue
{
    T qu[10];
    int front,rear,max=3;
    public:
    queue();
    void insert(T);
    void disp();
    T Delete();
    int isfull();
    int isEmpty();
    
};
template <class T>queue<T>::queue()
{
    front=rear=-1;
}
template <class T>int queue<T>::isfull(){
    if(rear==max-1)
    return 1;
else
    return 0;
}
template <class T>int queue<T>::isEmpty()
{
    if(rear==-1)
    return 1;
    else
    return 0;
}
template <class T>void queue<T>::insert(T element)
{
    rear++;
    qu[rear]=element;
    if(front==-1)
    {
        front++;
    
    }
}
    template <class T>void queue<T>::disp()
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<qu[i]<<" ";
        }
    
    }
    template <class T>T queue <T>::Delete(){

    T retval;
    retval=qu[front];
    front++;
    if(front>rear){
        front=rear=-1;
        return retval;
    }
    }
    int main(){
        queue <int> q;
        int ch,ele;
        while(ch!=4){
            cout<<"1. Insert"<<endl<<"2. Delete"<<endl<<"3. List"<<endl<<"4. Exit"<<endl;
            cout<<"Enter the choice ";
            cin>>ch;
            cout<<endl;
            switch(ch)
            {
                case 1 :if(q.isfull()) 
                {
             cout<<"stack is full"<<endl;
                }
                else{
                         cout<<"Enter the element to insert ";
                cin>>ele;
            
                q.insert(ele);
                
                cout<<endl;
                }
                
                break;
                
                case 2 : if(q.isEmpty())
                {
                    cout<<"Queue is Empty";
                }
                else
                {
                cout<<"Deleted element is 2";
             
                cout<<q.Delete()<<endl;
                }
                break;
                case 3 : cout<<"Elements in the queue ";
                q.disp();
                cout<<endl;
                
                break;
                
            }
        }
    }