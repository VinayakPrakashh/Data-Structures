#include<iostream>
using namespace std;
template<class T>class graph
{
  T gr[10][10];
  int nodes;
  public:
  void readgraph();
  void dispgraph();
  void spath();
  
};
  
template<class T>void graph<T>::readgraph(){
    int i,j,e,w,efrom,eto;
    cout<<"Enter the number of nodes "<<endl;
    cin>>nodes;
    for(i=0;i<nodes;i++){
        for(j=0;j<nodes;j++){
            if(i==j){
                gr[i][j]=0;
            }
                else{
                gr[i][j]=999;
                }
            }
        }
    
    cout<<"Enter the number of edges "<<endl;
    cin>>e;
    cout<<"Enter the edges "<<endl;
    for(i=0;i<e;i++){
        cin>>efrom>>eto>>w;
        gr[efrom][eto]=w;
    }
}
template <class T>void graph<T>::dispgraph()
{
    int i,j;
    cout<<"Entered Matrix"<<endl;
    for(i=0;i<nodes;i++){
        for(j=0;j<nodes;j++){
            cout<<gr[i][j]<<" ";;
            
        }
        cout<<endl;
    }
}
template<class T>void graph<T>::spath(){
    int i,j,k;
    cout<<"Shortest path"<<endl;
    for(k=0;k<nodes;k++){
        for(i=0;i<nodes;i++){
            for(j=0;j<nodes;j++){
                if(gr[i][j]>gr[i][k]+gr[k][j]){
                    gr[i][j]=gr[i][k]+gr[k][j];
                }
            }
        }
    }
     for(i=0;i<nodes;i++){
        for(j=0;j<nodes;j++){
            cout<<gr[i][j]<<" ";
            
        }
        cout<<endl;
    }
}
int main(){
    graph <int> l;
    int ch;
    while(ch!=3){
        cout<<"1. Read Matrix\n2. Display Matrix\n3. Shortest Path\n4. Exit";
        cout<<endl<<"Enter the choice "<<endl;
        cin>>ch;
        switch(ch){
            case 1:l.readgraph();
            break;
            case 2:l.dispgraph();
            break;
            case 3:   l.spath(); 
            break;
            case 4:
            break;


        }
    }

      
}
