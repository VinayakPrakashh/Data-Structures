#include<iostream>
using namespace std;

template<class T>
class BST
{
    class treenode{
        friend class BST;
        T data;
        treenode *lchild,*rchild;
    
    }*root;
       public:
    BST();
    void insert(T);
    void find(T);
    void inord();
    void inorder(treenode *);
    void preord();
    void preorder(treenode *);
    void postord();
    void postorder(treenode *);
    void Delete(int);
};
template<class T>BST<T>::BST()
{
    root=NULL;
}
template <class T>void BST<T>::insert(T item)
{
    treenode *p=root,*q;
    while(p!=NULL)
{
    q=p;
    if(item<p->data){
        p=p->lchild;
    }
    else{
        p=p->rchild;
    }}
    p=new treenode();
    p->lchild=NULL;
    p->rchild=NULL;
    p->data=item;
  // cout<<endl<<"In insert p "<<p<<" data "<<p->data;
   //cout<<endl<<"In insert q "<<q<<" data "<<q->data;
    if(root==NULL)
    {
        root=p;
    }
    else
    {
        if(item<q->data)
        {
            q->lchild=p;
        }
        else{
            q->rchild=p;
        }
    }
    
}
template<class T>void BST<T>::inord()
{
    inorder(root);
    
}
template<class T>void BST<T>::inorder(treenode *currentnode)
{
    if(currentnode){
        inorder(currentnode->lchild);
        cout<<currentnode->data<<" ";
        inorder(currentnode->rchild);
    }
}
    template<class T>void BST<T>::preord(){
        preorder(root);
    }
    template<class T>void BST<T>::preorder(treenode *currentnode)
{
    if(currentnode){
        cout<<currentnode->data<<" ";
        preorder(currentnode->lchild);
        preorder(currentnode->rchild);
    }
   
}
    template<class T>void BST<T>::postord(){
        postorder(root);
    }
    template<class T>void BST<T>::postorder(treenode *currentnode)
{
    if(currentnode){
       
        postorder(currentnode->lchild);
        postorder(currentnode->rchild);
         cout<<currentnode->data<<" ";
    }
}
template<class T>void BST<T>::find(T item){
    treenode *p=root;
    while(p!=NULL){
        if(item>p->data){
            p=p->rchild; 
        }
            else if(item<p->data){
                p=p->lchild;
            }
            else
            {
                break;
            }
            if(p==NULL){ 
              //  cout<<"element not found";
            }
            else{
            //    cout<<"element found";
                
            }
        }
    }
template<class T>void BST<T>::Delete(int item){
    treenode *p=root,*q;
    
    while(p!=NULL){
        q=p;
        if(item>(p->data)){
           
            p=p->rchild;
        }
        else if(item<(p->data)){
            p=p->lchild;
           
        }
        else {
            break;
        }
}
    if(p->rchild==NULL && p->lchild==NULL){ 
        delete p;
        if(p->data>item){
            q->rchild=NULL;
        }
        else{
            q->lchild=NULL;
        }
    }
    if(p->rchild!=NULL && p->lchild==NULL){ 
        cout<<"before "<<p->data<<endl;
        delete p;
         cout<<"after "<<p->data<<endl;
        if(p->data<item){
            q->rchild=NULL;
        }
        else{
            q->lchild=NULL;
             
        }
    }
  //  cout<<"deleted";
}
int main(){
    int ch,item;
    BST <int> b;
    while(ch!=6){
       // cout<<"1. insert\n2. Delete\n3. pre-order\n4. postorder\n5. in-order\n6. exit"<<endl;
      //  cout<<"enter your choice ";
        cin>>ch;
        switch(ch){
            case 1://cout<<"enter the element to insert ";
            cin>>item;
            b.insert(item);
            break;
            case 2: //cout<<"enter the element to delete ";
            cin>>item;
            b.Delete(item);
            break;
            case 3:
            b.preord();
            break;
            case 4:
            b.postord();
            break;
            case 5:
            b.inord();
            break;
            case 6:
            break;
            
        }
    }
    return 0;
}

