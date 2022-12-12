#include<iostream>
using namespace std;
template<class T>class quick{
    T arr[10];
    int n;
    public:
    void readarray();
    void sortarray();
    void sort(int,int);
    int partition(int,int);
    void printarray();
};
template<class T>void quick<T>::readarray(){
    cout<<"Enter the number of elements ";
    cin>>n;
    cout<<"Enter the elements ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
}
template<class T>void quick <T>::printarray(){
    cout<<"Sorted List ";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<"\t";
}
template<class T>void quick<T>::sortarray(){
    sort(0,n-1);
}
template<class T>void quick<T>::sort(int lb,int ub){
 int j;
 if(lb>ub)
 return;
 j=partition(lb,ub);
 sort(lb,j-1);
 sort(j+1,ub);
}
template<class T>int quick<T>::partition(int lb,int ub){
    int up,down;
    T a,temp;
    up=ub;
    down=lb;
    a=arr[lb];
    while(down<up){
        while(arr[down]<=a &&down<up)
        down++;
        while(arr[up]>a)
        up--;
        if(down<up){
            temp=arr[up];
            arr[up]=arr[down];
            arr[down]=temp;
        }
    }
    arr[lb]=arr[up];
    arr[up]=a;
    return up;
}
int main(){
    quick<int>q;
    q.readarray();
    q.sortarray();
    q.printarray();
}