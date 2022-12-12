#include <iostream>
using namespace std;
template <class T>
class Bubble
{
    T arr[10];
    int n;
    public:
    void readarray();
    void printarray();
    void sortarray();
};
template <class T> void Bubble<T>:: readarray()
{
    cout<<"Enter the number of elements "<<endl;
    cin>>n;
    cout<<"Enter the elements "<<endl;
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
}
template <class T>void Bubble<T>:: printarray()
{
    cout<<"Sorted list ";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}
template <class T> void Bubble<T> :: sortarray()
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                T temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main()
{
    Bubble <int> b;
    b.readarray();
    b.sortarray();
    b.printarray();
}