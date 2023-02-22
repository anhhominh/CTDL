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
			t->left = insert(t->left,x);
		} else {
			t->right = insert(t->right,x);
		}
	}
}

bool checkLeafNode(node *l){
	return (l->left == NULL && l->right == NULL);
}

int treeLevel(node *t){
	if(t == NULL) return -1;
	return 1 + max(treeLevel(t->left), treeLevel(t->right));
}

int main(){
	int n,tmp;
	cin >> n;
	node *t = NULL;
	for(int i=0; i<n; i++){
		cin>>tmp;
		t = insert(t,tmp);
	}
	cout << treeLevel(t);
	return 0;
}