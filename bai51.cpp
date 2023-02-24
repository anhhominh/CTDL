#include<iostream>

using namespace std;


void quickSort(int a[],int l,int r){
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
	if(j>l){
		quickSort(a,l,j);
	}
}

int main(){
	int a[100],b[100],n,i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	int dem = 0;
	for(i=0;i<n;i++){
		if(a[i]!=0){
			b[dem]=a[i];
			dem++;
		}
	}
	
	quickSort(b,0,dem-1);
	int k = 0;	
	for(i=n-1;i>=0;i--){
			if(a[i]<0){
			a[i]=b[k];
			k++;
			}
	}
	for(i=0;i<n;i++){
			if(a[i]>0){
				a[i] = b[k];
				k++;
		}
	}

	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}