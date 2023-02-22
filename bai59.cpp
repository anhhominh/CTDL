#include<iostream>

using namespace std;

int b[11], a[11];


void print(int a[],int n){
	for(int i=1; i<=n; i++){
		cout<< a[i];
	}
	cout<<" ";
}

void dequy(int k,int n){
	for(int i=1;i<=n;i++){
		if(a[i]){
			b[k] = i;
			if(k==n){ 
				print(b,n);
			}else {
				a[i] = false;
				dequy(k+1,n);
				a[i] = true;
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		a[i] = true;
	}
	dequy(1,n);
}