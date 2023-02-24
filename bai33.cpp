#include<iostream>

using namespace std;

int searchMin(int a[],int n){
	int k=0;
	for(int i=0;i<n;i++){
		if(a[k]>a[i]){
		k=i;
		}
	}
	return k;
}

int searchMax(int a[],int n){
	int k=0;
	for(int i=0;i<n;i++){
		if(a[k]<=a[i]){
			k=i;
		}
	}
	return k;
}

int swap(int &a,int &b){
	int tmp = a;
	a = b;
	b = tmp;
}
int main(){
	int a[100],n,i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	int csMin = searchMin(a,n);
	int csMax = searchMax(a,n);
	swap(a[csMin],a[csMax]);
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}