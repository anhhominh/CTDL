#include<iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

node *createNode(int x){
    node *temp = new node;//tạo mới một node
    temp->next = NULL; // node này chưa trỏ đến phần tử khác nên "next" nhận giá trị NULL
    temp->data = x;
    return temp;
}

node *addElement(node*p, int x){
    node *temp = createNode(x);// Tạo 1 node mới có giá trị là x
    p->next = temp;//thêm node đó và cuối danh sách
    return temp;// trả về node temp, vì temp giờ đã là node cuối của list
}

void printList(node *l){
    node *p = l;
    while(p != NULL){
        cout<< p->data << " ";
        p = p->next;
    }
}

int main(){
    int n,x;
    cin>>n;
    cin>>x;
    node *l = createNode(x);
    node *p = l;
    for(int i=1;i<n;i++){
        cin >> x;
        p = addElement(p,x);
    }
    printList(l);
    return 0;
}