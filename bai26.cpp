#include<iostream>

using namespace std;

struct node{
	int data;
	node *next;
};



node *createNode(int x){
	node *tmp = new node;
	tmp->data = x;
	tmp->next = NULL;
	return tmp;	
}

node *addElement(node*p, int x){
	node *tmp = createNode(x);
	p->next = tmp;
	return tmp;	
}

void print(node *l){
	node *p = l;
	while( p != NULL){
		cout<< p->data <<" ";
		p = p->next;
	}
}

node *addLast(node *l, int x){
	node *p = l;
	while ( p->next != NULL){
		p = p->next;
	}
	node *tmp = new node;
	tmp->data = x;
	tmp->next = NULL;
	p->next = tmp;
	return l;
}

node *getNode(node *l, int k){
	node *p=l;
	for(int i=0;i<k;i++){
		p = p->next;
	}
	return p;
}

node *deleteBigger(node *l, int k){
	node *p = l;
	node *ans = new node;
	while( p != NULL){
		if(p->data <= k){
			ans = createNode(p->data);
			p = p->next;
			break;
		}
		p = p->next;
	}
	while (p != NULL){
		if(p->data <= k){
			ans = addLast(ans, p->data);
		}
		p = p->next;
	}
	return ans;
}

int main(){
	int n,x,k;
	cin>>n;
	cin>>x;
	node *l = createNode(x);
	node *p = l;
	for(int i=1;i<n;i++){
		cin>>x;
		p = addElement(p,x);
	}
	cin>>k;
	l = deleteBigger(l, getNode(l,k)->data);
	print(l);
	return 0;
}                            