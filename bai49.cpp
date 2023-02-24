#include<iostream>

using namespace std;

void quickSort(int a[], int l, int r){
	int p = a[(l+r)/2];
	int i = l, j = r;
	while(i<j){
		while(a[i]<p){
			i++;
		}
		while(a[j]>p){
			j--;
		}
		if(i<=j){
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}
	if(i<r){
		quickSort(a,i,r);
	}
	if(l<j){
		quickSort(a,l,j);
	}
}

int result(int a[], int n, int k){
	int count =0;
	for(int i=1;i<n;i++){
		if(a[i]-a[i-1]>k){
			count++;
		}
	}
	return count + 1;
}
int main(){
	int a[100],n,i,k;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	quickSort(a,0,n-1);
	cin>>k;
	cout<< result(a,n,k);
	return 0;
}