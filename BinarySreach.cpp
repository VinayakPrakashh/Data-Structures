
#include <iostream>
using namespace std;

template <class T>
class BST{
	class treenode{

		friend class BST;
	public:
		T data;
		treenode *lchild,*rchild;

	}*root;
	int m_size,max=16;
public:
	BST();
	void insert(T);
	int isempty();
	int isfull();
	void inorder(treenode *);
	void inord();
	void preorder(treenode *);
		void preord();
		void postorder(treenode *);
			void postord();
			int find(T);

			treenode * mindataNode(treenode * node){
			  treenode *current = node;

			  while (current -> lchild != NULL) {
			    current = current -> lchild;
			  }
			  return current;
			}
			void deleteNod(int v){
				deleteNode(root,v);
			}
			treenode * deleteNode(treenode *r, int v) {

			    if (r == NULL) {
			      return NULL;
			    }

			    else if (v<r->data) {
			      r -> lchild = deleteNode(r -> lchild, v);
			    }

			    else if (v>r->data) {
			      r -> rchild = deleteNode(r -> rchild, v);
			    }

			    else {

			      if (r->lchild==NULL) {
			        treenode * temp = r -> rchild;
			        delete r;
			        return temp;
			      } else if (r -> rchild == NULL) {
			        treenode * temp = r -> lchild;
			        delete r;
			        return temp;
			      } else {

			        treenode * temp = mindataNode(r -> rchild);

			        r -> data = temp -> data;

			        r -> rchild = deleteNode(r -> rchild, temp -> data);

			      }
			    }
			    return r;
			  }
};
template<class T>BST<T>::BST(){
	root=NULL;
	m_size=0;
}
template<class T>int BST<T>::isempty(){
	if(root==NULL)
		return 1;

	else
		return 0;
}
template<class T>int BST<T>::isfull(){
	if(m_size==max-1)
		return 1;

	else
		return 0;
}
template<class T>void BST<T>::insert(T item){

	if(isfull()){
		cout<<"insufficient storage"<<endl;
	}
	else{
	treenode *p=root,*q;
	while(p!=NULL){
		q=p;
		if(item<p->data){
			p=p->lchild;
		}
		else{
			p=p->rchild;
		}
	}
	p=new treenode();
	p->rchild=NULL;
	p->lchild=NULL;
	p->data=item;
	if(root==NULL){
		root=p;
	}
	else{
		if(item<q->data){
			q->lchild=p;

		}
		else{
			q->rchild=p;
		}
	}
	m_size++;
	}
}
template<class T>void BST<T>::inord(){
	if(isempty()){
		cout<<"Nothing to display"<<endl;
	}
	else{
	inorder(root);
	}
}
template<class T>int BST<T>::find(T item){
	treenode *p=root;
	while(p!=NULL)
{
		if(item>p->data)
			p=p->rchild;
		else if(item<p->data){
		p=p->lchild;
		}
		else
			break;
}
	if(p==NULL){
		return 1;
	}
	else
		return 0;
}
template<class T>void BST<T>::inorder(treenode *currentnode){
	if(currentnode){
		inorder(currentnode->lchild);
				cout<<currentnode->data<<" ";
				inorder(currentnode->rchild);
	}

}
template<class T>void BST<T>::preord(){
	if(isempty()){
		cout<<"Nothing to display"<<endl;
	}
	else{
	preorder(root);
	}
}
template<class T>void BST<T>::preorder(treenode *currentnode){
	if(currentnode){
		cout<<currentnode->data<<" ";
		preorder(currentnode->lchild);
				preorder(currentnode->rchild);
	}

}
template<class T>void BST<T>::postord(){
	if(isempty()){
		cout<<"Nothing to display"<<endl;
	}
	else{
	postorder(root);
	}
}
template<class T>void BST<T>::postorder(treenode *currentnode){
	if(currentnode){
		postorder(currentnode->lchild);
				postorder(currentnode->rchild);
				cout<<currentnode->data<<" ";
	}

}
int main(){
	BST <int> s;
	int ch,elem,val;

	while(ch!=6){
		cout<<"1. insert\n2. inorder\n3. preorder\n4. postorder\n5. Delete\n6. exit"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>ch;
		switch(ch){
		case 1:cout<<"enter the element to insert "<<endl;
		cin>>elem;
		s.insert(elem);
		cout<<elem<<" inserted successfully"<<endl;
		break;
		case 2:s.inord();
		break;
		case 3:s.preord();
				break;
		case 4:s.postord();
				break;
		case 5:cout << "DELETE" << endl;
	      cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
	      cin >> val;
	      if(s.find(val)){
	    	  cout<<"Element not found"<<endl;
	      }
	      else{
	        s.deleteNod(val);
	        cout << "Value Deleted" << endl;
	      }
		break;
		default :cout<<"Enter valid choice"<<endl;
		}
	}
	cout<<"Exited"<<endl;
}
