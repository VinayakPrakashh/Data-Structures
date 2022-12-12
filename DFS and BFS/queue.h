#include<iostream>
#include<stdlib.h>

using namespace std;

template <class T> class QueueADT
{
             int max,front,rear;
             T queue[10];
      public:

             QueueADT();
             int isFull();
             int IsEmpty();
             void Insert(T data);
             T Delete();
             void showQueue(); 
};

template <class T> QueueADT <T> :: QueueADT()     
{
                max=5;
                front=rear=-1;
}

template <class T> int QueueADT <T> :: isFull()
{
	if ((rear+1)%max==front)
		return 1;
	else 
		return 0;
}

template <class T> int QueueADT <T> :: IsEmpty()
{
	if (front==-1)
		return 1;
	else 
		return 0;
}

template <class T> void QueueADT <T> :: Insert(T data)
{
	if(isFull())
        {
        	cout << "Queue FULL..!!";
			return;
	}
        else if(front==-1)
        {
          front=0;
          rear=0;
        }
        else rear=(rear+1)%max;
              
        queue[rear]=data;
	}
template <class T> T QueueADT <T> :: Delete()
{  
	T pdata=-1;
     if(IsEmpty())
	{
		cout << "Queue EMPTY..!!";
                         
	}
        
        else
        {
	    pdata=queue[front];
            if(front==rear)
             {
                front=rear=-1;
             }
	     else
              front=(front+1)%max;
           
	}
	return pdata;
}
template <class T> void QueueADT <T> :: showQueue()
{
	if(IsEmpty())
   
        {
                cout<<"\nShow:"<<rear<<endl;
		cout << "Queue EMPTY..!!"; 
                return;                
	}
		for (int i=front; i<=rear; i++) cout << queue[i] << " ";
	
}
