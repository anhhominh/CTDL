#include<iostream>

using namespace std;

void insertionSort(int a[],int n){
	int index,value;
	for(int i=1;i<n;i++){
		index =i;
		value = a[i];
		while(index > 0 && a[index-1] > value){
			a[index] = a[index -1];
			index--;
		}
		a[index] = value;
	}
}
int main(){
	int a[100],n,i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	insertionSort(a,n);
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}