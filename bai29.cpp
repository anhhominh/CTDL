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

douList *addLast(douList *l,int x){
	node *tmp = new node;
	tmp->data = x;
	tmp->next = NULL;
	tmp->pre = l->tail;
	l->tail->next = tmp;
	l->tail = tmp;
	return l;
}

douList *deleteHead(douList *l){
	node *p = l->head->next;
	node *tmp = l->head;
	p->pre = NULL;
	l->head = p;
	delete(tmp);
	return l;
}

douList *deleteLast(douList *l){
	node *p = l->tail->pre;
	node *tmp = l->tail;
	p->next = NULL;
	l->tail = p;
	delete(tmp);
	return l;
}

douList *deleteAt(douList *l,int k){
	node *p = l->head;
	for(int i=0;i< k-1;i++){
		p = p->next;
	}
	node *tmp = p->next;
	node *p2 = tmp->next;
	p->next = p2;
	p2->pre = p;
	delete(tmp);
	return l;
}

void printList(douList *l){
	node *p = l->head;
	while (p != NULL){
		cout << p->data << " ";
		p = p->next;
	}
}

int main(){
	int n, x, k;
	cin >> n;
	cin >> x;
	douList *l = createList(x);
	for (int i = 1; i < n; i++){
		cin >> x;
		l = addLast(l, x);
	}
	cin >> k;
	if (k == 0){
		l = deleteHead(l);
	} else if (k == n-1){
		l = deleteLast(l);
	} else {
		l = deleteAt(l, k);
	}
	printList(l);
	return 0;
}