/*
Cho một dãy gồm n số nguyên, hãy cài đặt dãy đó vào cây nhị phân tìm kiếm bằng cách sau,
 phần tử đầu tiên được chọn làm gốc, các phần tử tiếp theo được chèn và cây nhị phần theo cách: 
 node con bên trái luôn nhỏ hơn node cha, node con bên phải luôn lớn hơn học bằng node cha.

Hãy biến đổi cây đó thành cây AVL. Nhập vào một số nguyên x, 
hãy đếm số lượng phần tử có giá trị bằng x trong cây đó.
*/

#include<iostream>
#include<math.h>

using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

node *insert(node *t, int x){
	if (t == NULL){
		node *temp = new node;
		temp->data =x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	} else{
		if (x < t->data){
			t->left = insert(t->left, x);
		} else{
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
	if( abs(treeLevel(t->left) - treeLevel(t->right)) > 1) return false;
	return checkAvl(t->left) && checkAvl(t->right);
}

node *turnLeft(node *a){
	node *b = a->right;
	node *c = b->left;
	a->right = c;
	b->left = a;
	return b;
}

node *turnRight(node *a){
	node *b = a->left;
	node *d = b->right;
	a->left = d;
	b->right = a;
	return b;
}

node *updateTreeAvl(node *t){
	if(abs(treeLevel(t->left) - treeLevel(t->right)) > 1){
		if(treeLevel(t->left) > treeLevel(t->right)){
			node *p = t->left;
			if(treeLevel(p->left) >= treeLevel(p->right)){
				t = turnRight(t);
			} else {
				t->left = turnLeft(t->left);
				t = turnRight(t);
			}
		} else {
			node *p = t->right;
			if(treeLevel(p->right) >= treeLevel(p->left)){
				t = turnLeft(t);
			} else {
				t->right = turnRight(t->right);
				t = turnLeft(t);
			}
		}
	}
	if(t->left != NULL) t->left = updateTreeAvl(t->left);
	if(t->right != NULL) t->right = updateTreeAvl(t->right);
	return t;
}

int count(node *t, int x){
	if(t == NULL) return 0;
	if(t->data == x) return 1 + count(t->left, x) + count(t->right, x);
	else if(t->data < x) return count(t->right, x);
	return count(t->left, x);
}

int main(){
	int n, x, temp;
	cin >> n;
	node * t = NULL;
	for (int i = 0; i < n; i++){
		cin >> temp;
		t = insert(t, temp);
	}
	while(!checkAvl(t)){
		t = updateTreeAvl(t);		
	}
	cin >> x;
	cout << count(t, x);
	return 0;
}