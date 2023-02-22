#include<iostream>

using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

node *insert(node *t, int x){
	if(t == NULL){
		node *tmp = new node;
		tmp->data = x;
		tmp->left = NULL;
		tmp->right = NULL;
		return tmp;
	} else {
		if( x < t->data){
			t->left = insert(t->left, x);
		} else {
			t->right = insert(t->right, x);
		}
	}
}

bool isLeafNode(node *l){
	return (l->left == NULL && l->right == NULL);
}

int dem(node *t){
	if(t == NULL) return 0;
	if(isLeafNode(t)) return 1;
	return dem(t->left) + dem(t->right);
}
int main(){
	int n,tmp;
	cin>>n;
	node *t = NULL;
	for(int i=0; i<n; i++){
		cin >> tmp;
		t = insert(t,tmp);
	}
	cout<< dem(t);
	return 0;
}