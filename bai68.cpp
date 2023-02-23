/*
Cho một dãy gồm n số nguyên, hãy cài đặt dãy đó vào cây nhị phân tìm kiếm bằng cách sau, 
phần tử đầu tiên được chọn làm gốc, các phần tử tiếp theo được chèn và cây nhị phần theo cách: 
node con bên trái luôn nhỏ hơn node cha, node con bên phải luôn lớn hơn học bằng node cha.

Cuối cùng nhập một sô nguyên x, hãy xóa những node có giá trị bằng x (các node con của nó cũng bị xóa theo). 
In các phần tử trong cây theo cách duyệt trung thứ tự. Nếu cây rỗng in ra "NULL".
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

void printTree(node *t){
	if(t != NULL){
		printTree(t->left);
		cout<< t->data << " ";
		printTree(t->right);
	}
}

void deleteNode(node *t){
	if(t != NULL){
		if(t->left != NULL) deleteNode(t->left);
		if(t->right != NULL) deleteNode(t->right);
		delete(t);
	}
}

node *deleteNumber(node *t, int x){
	if(t != NULL){
		if(t->data == x){
			deleteNode(t->left);
			deleteNode(t->right);
			t = NULL;
		}
		else if (t->data > x) t->left = deleteNumber(t->left,x);
		else t->right = deleteNumber(t->right, x);
	}
	return t;
}
int main(){
	int n,tmp,x;
	cin>>n;
	node *t = NULL;
	for(int i=0;i<n;i++){
		cin>>tmp;
		t = insert(t, tmp);
	}
	cin >> x;
	t = deleteNumber(t, x);
	if(t == NULL) cout << "NULL";
	else printTree(t);
	return 0;
}