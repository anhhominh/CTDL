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

douList *addLast(douList *l, int x){
	node *tmp = new node;
	tmp->data = x;
	tmp->next = NULL;
	tmp->pre = l->tail;
	l->tail->next = tmp;
	l->tail = tmp;
	return l;
}

void print(douList *l){
	node *p = l->head;
	while(p != NULL){
		cout << p->data << " ";
		p = p->next;
	}
}

int main(){
	int n;
	cin>>n;
	douList *l = createList(1);
	for(int i=2;i<=n;i++){
		l = addHead(l,i);
		l = addLast(l,i);
	}
	print(l);
	return 0;
}