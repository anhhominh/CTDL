#include<iostream>
#include<math.h>

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

int treeLevel(node *t){
	if(t == NULL) return -1;
	return 1 + max(treeLevel(t->left), treeLevel(t->right));
}

bool checkAvl(node *t){
	if(t == NULL) return true;
	if(abs(treeLevel(t->left) - treeLevel(t->right)) > 1) return false;
	if(checkAvl(t->left) == false) return false;
	if(checkAvl(t->right) == false) return false;
	return true;
	
}
int main(){
	int n,tmp;
	cin>>n;
	node *t = NULL;
	for(int i=0;i<n;i++){
		cin>>tmp;
		t = insert(t, tmp);
	}
	if(checkAvl(t)==true){
	cout<<"true";
	} else cout<<"false";
	return 0;
}