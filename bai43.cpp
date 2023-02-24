// Selection Sort

#include<iostream>

using namespace std;

void selectionSort(int a[],int n){
	int indexMin;
	for(int i=0;i<n;i++){
		indexMin=i;
		for(int j=i+1;j<n;j++){
			if(a[indexMin]>a[j]){
				indexMin = j;
			}
		}
		if(indexMin != i ){
			int tmp = a[i];
			a[i] = a[indexMin];
			a[indexMin] = tmp;
		}
	}
}
int main() {
	int a[100],n,i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	selectionSort(a,n);
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}