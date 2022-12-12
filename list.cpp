#include<iostream>
using namespace std;
template <class T> class list
{
    T lst[10];
    int cnt,flag,i;
    public:
    list();
    void insert(T,int);
    void disp();
    void findk(int);
    void find(T);
    void Delete(int);
};
template <class T>list<T>::list()
{
    cnt=0;
}
template <class T>void list<T>::insert(T ele,int pos)
{
    if(pos<cnt)
    {
        cout<<"Insertion is not possible";
    }
    else
    {
        for(int i=cnt;i>=pos;i--)
        {
            lst[i]=lst[i-1];
        }
        lst[pos-1]=ele;
        cnt++;
        }
}
template <class T>void list<T>::disp()
{
    for(int i=0;i<cnt;i++)
    {
        cout<<lst[i]<<" ";
}
}
template <class T>void list<T>::findk(int pos)
{
    cout<<"Element in position "<<pos<<" is "<<lst[pos-1];
}
template <class T>void list<T>::find(T ele)
{
for(i=1;i<=10;i++)
{
    if(lst[i]=ele)
    {
        flag=1;
        break;
    }
}
if(flag=1)
{
    cout<<"Element is in position "<<i+1<<endl;
}
}
template <class T>void list<T>::Delete(int pos)
{
  cout<<"Deleted element is "<<lst[pos-1]<<endl;
  for(i=(pos-1);i<cnt;i++){
    lst[i]=lst[i+1];  
  }
cnt--;
}
int main()
{
    list<int> l;
    int ch,elem,posi;
    while(ch!=6)
    {
        cout<<"\n1. Insert\n2. Delete\n3. List\n4. Find\n5. Find kth\n6. Exit"<<endl;
        cout<<"Enter your choice ";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
            case 1 : cout<<"Enter the element and position ";
            cin>>elem>>posi;
            l.insert(elem,posi);
            break;
            case 2 : cout<<"Enter the position ";
            cin>>posi;
            l.Delete(posi);
            break;
            
        
            case 3 : cout<<"Elements in the list - ";
            l.disp();
            break;
            case 4 : cout<<"Enter the element to find "<<endl;
                cin>>elem;
                l.find(elem);
                break;
            case 5 : cout<<"Enter the position ";
            cin>>posi;
            l.findk(posi);
            break;
        }
    }
}