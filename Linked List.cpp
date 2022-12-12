#include <iostream>
using namespace std;

template <class T>
class linkedlist{
	class node{
		friend class linkedlist;
	public:
		T data;
		node *next;

		node(T item,node *nx=NULL){
			data=item;
			next=nx;
		}


	}*m_head,*m_tail;
public:
	int m_size,max;
	linkedlist();
	int isempty();
	int isfull();
	void addhead(T);
	void addtail(T);
	void list();
	void removehead();
	void removetail();
	void find(T);
	void findkth(int);
	void addnode(T,int);
	void emptylist();
	void removenode(int);
};
template <class T>linkedlist<T>::linkedlist(){
	m_head=NULL;
	m_tail=NULL;
	m_size=0;
	max=6;
}
template<class T>int linkedlist<T>::isempty(){
	if(m_head==NULL)
	return 1;

	else
		return 0;

}
template<class T>int linkedlist<T>::isfull(){
	if(m_size==max-1)
		return 1;


	else
		return 0;
}
template<class T>void linkedlist<T>::addhead(T item){
	if(isfull()){
		cout<<"list is full"<<endl;
		int num;
					cout<<"Do you want to remove elements?"<<endl;
					cout<<"press 1 for YES / press 0 for NO"<<endl;
					cin>>num;
					while(num==1){
						int posi;
						cout<<"enter the position of the element"<<endl;
						cin>>posi;
						removenode(posi);
						break;
					}
	}
	else{
	m_head=new node(item,m_head);
	if(m_tail==NULL){
		m_tail=m_head;
	}
	m_size++;
	cout<<"Added "<<item<<" successfully"<<endl;
	}


}
template <class T>void linkedlist<T>::addtail(T item){
	if(isfull()){
		cout<<"list is full"<<endl;
		int num;
					cout<<"Do you want to remove elements?"<<endl;
					cout<<"press 1 for YES / 0 for NO"<<endl;
					cin>>num;
					while(num==1){
						int posi;
						cout<<"enter the position of the element"<<endl;
						cin>>posi;
						removenode(posi);
						break;
					}
	}
	else{
	if(m_tail==NULL){
		addhead(item);
	}
	else{
		node *temp=m_tail;
		m_tail->next=new node(item);
		m_tail=temp->next;
		m_size++;
		cout<<"Added "<<item<<" successfully"<<endl;

	}
	}


}
template <class T>void linkedlist<T>::removehead(){
	if(isempty()){
		cout<<"No head to remove"<<endl;
		int num;
						cout<<"do you want to add elements?"<<endl;
						cout<<"press 1 for YES / press 0 for NO"<<endl;
				cin>>num;
				while(num==1){
					T item;
					int posi;
					cout<<"enter the element and position"<<endl;
					cin>>item>>posi;
					addnode(item,posi);
					break;
				}
	}
	else{
	node *temp=m_head;
	m_head=temp->next;
	delete temp;
	cout<<"head removed";
	m_size--;
	}
}
template <class T>void linkedlist<T>::removetail(){

	if(isempty()){
		cout<<"list is empty"<<endl;
		int num;
				cout<<"do you want to add elements?"<<endl;
				cout<<"press 1 for YES / press 0 for NO"<<endl;
		cin>>num;
		while(num==1){
			T item;
			int posi;
			cout<<"enter the element and position"<<endl;
			cin>>item>>posi;
			addnode(item,posi);
			break;
		}
	}
	else{
if(m_head==m_tail){
	m_head=m_tail=NULL;
}
else{
	node *temp=m_head;
	while(temp->next!=m_tail){
		temp=temp->next;
	}
	temp->next=NULL;
	delete m_tail;
	m_tail=temp;
	m_size--;
	}
	}
}
template <class T>void linkedlist<T>::find(T item){
	if(isempty()){
		int num;
		cout<<"cannot find any element because list is empty"<<endl;
		cout<<"do you want to add elements?"<<endl;
				cout<<"press 1 for YES / press 0 for NO"<<endl;
		cin>>num;
		while(num==1){
			T item;
			int posi;
			cout<<"enter the element and position"<<endl;
			cin>>item>>posi;
			addnode(item,posi);
			break;
		}
	}
	else{
	node *temp=m_head;
	int flag=0,size=1;
	while(temp!=NULL){
		if(temp->data==item){
			flag++;
			break;
		}
		temp=temp->next;
		size++;
	}
	if(flag!=0){
		cout<<"element found at "<<size<<" th position"<<endl;
	}
	else
		cout<<"element not found"<<endl;
	}
}
template <class T>void linkedlist<T>::findkth(int pos){
	if(isempty()){
		cout<<"list is empty"<<endl;
		int num;
		cout<<"do you want to add elements?"<<endl;
						cout<<"press 1 for YES / press 0 for NO"<<endl;
				cin>>num;
				while(num==1){
					T item;
					int posi;
					cout<<"enter the element and position"<<endl;
					cin>>item>>posi;
					addnode(item,posi);
					break;
				}

	}
	else{
node *temp=m_head;
while(pos!=1){
	temp=temp->next;
	pos--;

}
cout<<"element at the position is"<<temp->data<<endl;
	}
}
template<class T>void linkedlist<T>::list(){
	if(isempty()){
		cout<<"nothing to display";
		int num;
				cout<<"do you want to add elements?"<<endl;
				cout<<"press 1 for YES / press 0 for NO"<<endl;
		cin>>num;
		while(num==1){
			T item;
			int posi;
			cout<<"enter the element and position"<<endl;
			cin>>item>>posi;
			addnode(item,posi);
			break;
		}
	}
	else{
	node *temp=m_head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;

	}
	}
	cout<<endl;
}
template <class T>void linkedlist<T>::addnode(T item,int pos){
	if(isempty()){
		addhead(item);
	}
	else{
		if(isfull()){
			cout<<"list is full"<<endl;
			int num;
			cout<<"Do you want to remove elements?"<<endl;
			cout<<"press 1 for YES / press 0 for NO"<<endl;
			cin>>num;
			while(num==1){
				int posi;
				cout<<"enter the position of the element"<<endl;
				cin>>posi;
				removenode(posi);
				break;
			}

		}
		else{
			if(pos==1){
				addhead(item);
			}
			else if(pos==m_size+1){
				addtail(item);
			}
			else{
	node *temp2=m_head;
	node *temp3;
	node *temp=new node(item);
	while(pos!=2){
		temp2=temp2->next;
		pos--;
	}
	temp3=temp2->next;
	temp2->next=temp;
	temp->next=temp3;
	m_size++;
	cout<<"added successfully";
			}
		}
	}
}
template<class T>void linkedlist<T>::emptylist(){
	m_head=NULL;
	m_tail=NULL;
	m_size=0;
}
template<class T>void linkedlist<T>::removenode(int pos){
	if(isempty()){

		cout<<"list is empty"<<endl;
		int num;
		cout<<"do you want to add elements?"<<endl;
		cout<<"press 1 for YES / press 0 for NO"<<endl;
cin>>num;
while(num==1){
	T item;
	int posi;
	cout<<"enter the element and position"<<endl;
	cin>>item>>posi;
	addnode(item,posi);
	break;
}

	}
	else{
if(pos==1){
	removehead();
}
else if(pos==m_size+1){
	removetail();
}
else{
	node *temp=m_head;
	while(pos!=2){
		temp=temp->next;
		pos--;
	}
	node *temp2=temp->next;
			node *temp3=temp2->next;
	temp->next=temp3;
	delete temp2;
	m_size--;
}
	}
}
int main(){
	linkedlist <int> s;
	int item,ch,ps;

	while(ch!=11){
		cout<<"1. Addhead\n2. addtail\n3. removehead\n4. removetail\n5. find\n6. findkth\n7. add a node\n8. free list\n9. removenode\n10 list\n11. exit"<<endl;
			cout<<"enter your choice"<<endl;
			cin>>ch;
		switch(ch){
		case 1:cout<<"enter the value to add"<<endl;
		cin>>item;
		s.addhead(item);
		break;
		case 2:cout<<"enter the value to add"<<endl;
		cin>>item;
		s.addtail(item);
		break;
		case 3:s.removehead();
		break;
		case 4:s.removetail();
		break;
		case 5:cout<<"enter the element to find"<<endl;
		cin>>item;
		s.find(item);
		break;
		case 6:cout<<"enter the position"<<endl;
		cin>>ps;
		s.findkth(ps);
		break;
		case 7:cout<<"enter the element and the position"<<endl;
		cin>>item>>ps;
		s.addnode(item,ps);
		break;
		case 8:
			s.emptylist();
			cout<<"list cleared"<<endl;
			break;
		case 9:cout<<"enter the position"<<endl;
		cin>>ps;
		s.removenode(ps);
		cout<<"node removed"<<endl;
		break;
		case 10:s.list();
		break;
		}
	}
}
