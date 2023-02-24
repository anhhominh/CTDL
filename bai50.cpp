#include<iostream>
#include<math.h>
using namespace std;

void quickSort(int a[],int l,int r){
	int p=a[(l+r)/2];
	int i=l,j=r;
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

bool ktchinhphuong(int n){
	int k = (int) sqrt(n);
	return k*k == n;
}
int main(){
	int a[10001],b[100001],n,i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	int dem = 0;
	for(i=0;i<n;i++){
		if(ktchinhphuong(a[i])){
			b[dem]=a[i];
			dem++;
		}
	}
    quickSort(b,0,dem-1);
	if(dem==0)cout<<"NULL";
	for(i=0;i<dem;i++){
		if(b[i]!=b[i+1])cout<<b[i]<<" ";
	}
	return 0;
}