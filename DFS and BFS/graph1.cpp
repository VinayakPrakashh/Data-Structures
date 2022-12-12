#include<iostream>
using namespace std;
#include "stack.h"
#include "queue.h"
template <class T>class graph{
    
T gr[10][10];
int nodes;
int visited[10];
public:
graph(int);
void makegraph();

void DFS();
void disgraph();
void BFS();


};
template <class T>graph<T>::graph(int n){
    nodes=n;
}
template<class T>void graph<T>::makegraph(){
    int e,efrom,eto,i,j;
    cout<<"Enter the number of nodes"<<endl;
    cin>>nodes;
    cout<<"Enter the number of edges"<<endl;
    cin>>e;
    for(i=0;i<nodes;i++){
        for(j=0;j<nodes;j++){
            gr[i][j]=0;
            
            
        }
    }
    cout<<"enter the edges "<<endl;
    for(i=0;i<e;i++){
        cin>>efrom>>eto;
        gr[efrom][eto]=1;
        gr[eto][efrom]=1;
    }
}
template<class T>void graph<T>::disgraph(){
    int i,j;
    cout<<"Adjacency Matrix"<<endl;
    for(i=0;i<nodes;i++){
        for(j=0;j<nodes;j++){
            cout<<gr[i][j]<<" ";
            
        }
        cout<<endl;
    }
}
template <class T>void graph<T>::DFS(){
    int i,j,v;
    stack <int> s;
    cout<<"DFS"<<endl;
    for(i=0;i<nodes;i++){
        visited[i]=0;
    }
        s.push(0);
        visited[0]=1;
        while(!s.isEmpty()){
           
            v=s.pop();
             cout<<v<<" ";
            
            for(i=0;i<nodes;i++){
                if(gr[v][i]==1){
                    if(visited[i]==0){
                        s.push(i);
                        visited[i]=1;
                    }
                }
            }
        }
    cout<<endl;
}
template<class T>void graph<T>::BFS(){
    int k,j,v;
     QueueADT<int>q;
    cout<<"BFS"<<endl;   
    for(k=0;k<nodes;k++){
        visited[k]=0;
       
    }
        q.Insert(0);
        visited[0]=1;
        while(!q.IsEmpty()){
            v=q.Delete();
            cout<<v<<" ";
            for(k=0;k<nodes;k++){
                if(gr[v][k]==1){
                    if(visited[k]==0){
                        q.Insert(k);
                        visited[k]=1;
                    }
                }
            }
        }
    cout<<endl;
    exit(0);
}

int main(){
    graph <int> g(5);
    int ch;
    while(ch!=5){
        cout<<"1. Read Matrix\n2. Display Matrix\n3. DFS\n4. BFS\n5. Exit "<<endl;
        cout<<"Enter the choice"<<endl;
        cin>>ch;
        switch(ch){
            case 1:g.makegraph();
            break;
            case 2:g.disgraph();
            break;
            case 3:g.DFS();
            break;
            case 4:g.BFS();
            break;
            case 5:
            break;
        }
    }
}