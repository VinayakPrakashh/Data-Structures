#include<iostream>
using namespace std;
template<class T>class linkedlist{
    class node{
        friend class linkedlist;
        T data;
        node *next;
        node(T item,node *nx=NULL)
        {
            data=item;
            next=nx;
        }
    }*head,*tail;
    public:
    linkedlist();
    void insert(T);
    void Delete();
    void list();
};
template<class T>linkedlist<T>::linkedlist(){
    head=NULL;
    tail=NULL;
}
template<class T>void linkedlist<T>::insert(T data){
    if(head==NULL){
        head=new node(data);
        tail=head;
    }
    else{
        node *temp=tail;
        tail=new node(data);
        temp->next=tail;
    }
}
template<class T>void linkedlist<T>::Delete(){
    node *temp=head;
    head=head->next;
    cout<<temp->data<<endl;
    delete temp;
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
    int ch,data;
    while(ch!=4){
        cin>>ch;
        switch(ch){
            case 1:
            cin>>data;
            b.insert(data);
            break;
            case 2:
            b.Delete();
            break;
            case 3:
            b.list();
            break;
        }
    }
}