#include<iostream>

using namespace std;

int search(int a[],int n,int x){
	for(int i=0;i<n;i++){
		if(a[i]==x){
			return i;
		}
	}
	return -1;
}

int main(){
	int a[100],n,x,i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>x;
	cout<<search(a,n,x);
	return 0;
}