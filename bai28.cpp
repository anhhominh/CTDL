#include<iostream>

using namespace std;

struct node{
	int data;
	node *next;
	node *pre;
};

struct douList{
	node *head;
	node *tail;
};

douList *createList(int x){
	douList *l = new douList;
	l->head = new node;
	l->head->data = x;
	l->head->pre = NULL;
	l->head->next = NULL;
	l->tail = l->head;
	return l;
}

douList *addHead(douList *l, int x){
	node *tmp = new node;
	tmp->data = x;
	tmp->pre = NULL;
	tmp->next = l->head;
	l->head->pre = tmp;
	l->head = tmp;
	return l;
}

douList *addLast(douList *l,int x){
	node *tmp = new node;
	tmp->data = x;
	tmp->pre = l->tail;
	tmp->next = NULL;
	l->tail->next = tmp;
	l->tail = tmp;
	return l;
}

douList *addAt(douList *l, int k,int x){
	node *p = l->head;
	for(int i=0;i<k-1;i++){
		p = p->next;
	}
	node *tmp = new node;
	tmp->data = x;
	tmp->pre = p;
	tmp->next = p->next;
	p->next->pre = tmp;
	p->next = tmp;
	return l;
}

void print(douList *l){
	node *p = l->head;
	while(p != NULL){
		cout<< p->data << " ";
		p = p->next;
	}
}

int main(){
	int n,x,k;
	cin>>n;
	cin>>x;
	douList *l = createList(x);
	for(int i=1;i<n;i++){
		cin>>x;
		l = addLast(l,x);
	}
	cin>>k>>x;
	if(k==0){
		l = addHead(l,x);
	} else if(k==n){
		l = addLast(l,x);
	} else {
		l = addAt(l,k,x);
	}
	print(l);
	return 0;
}