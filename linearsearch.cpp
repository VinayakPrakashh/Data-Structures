#include<iostream>
using namespace std;

template <class T>class linear
{
    T arr[10];
    int size;
    public:
    void sizeofarray();
    void searchelement(T);
};
template <class T>void linear<T>::sizeofarray(){
    int i;
    cout<<"Enter the number of element "<<endl;
    cin>>size;
    cout<<"Enter the elements "<<endl;
    for(i=0;i<size;i++){
        cin>>arr[i];
    }
}
template <class T>void linear<T>::searchelement(T item){
    int i;

    for(i=0;i<size;i++){
        if(arr[i]==item){
            cout<<"Element found in position "<<i+1<<endl;
            break;
            
        }
    }
    if(i==size){
        cout<<"Element not found"<<endl;
    }
}
int main(){
    linear <int> l;
    int item;
    
    l.sizeofarray();
        cout<<"Enter the element to search "<<endl;
    cin>>item;
    l.searchelement(item);
}