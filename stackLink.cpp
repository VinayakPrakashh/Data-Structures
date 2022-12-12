#include<iostream>
using namespace std;
template<class T>class linkedlist
{
    class node
    {
        friend class linkedlist;
        T data;
        node *next;
        public:
        node(T item,node *nx)
        {
            data=item;
            next=nx;
        }
    }*head;
    public:
    linkedlist();
    void push(T);
    T pop();
    void list();
};
template<class T> linkedlist<T>::linkedlist(){
    head=NULL;
}
template<class T>void linkedlist<T>::push(T data){
    head=new node(data,head);
}
template<class T>T linkedlist<T>::pop(){
    node *temp=head;
    T data=temp->data;
    head=head->next;
    delete temp;
    return data;
}
template<class T>void linkedlist<T>::list(){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    linkedlist<int> b;
    int ch,item;
    while(ch!=4){
     //  cout<<"1.PUSH\n2.POP\n3.List\n4.Exit"<<endl;
        cin>>ch;
        switch(ch){
            case 1://cout<<"enter the element to push"<<endl;
            cin>>item;
            b.push(item);
            break;
            case 2:cout<<b.pop()<<endl;
            break;
            case 3:b.list();
            break;
        }
    }
}