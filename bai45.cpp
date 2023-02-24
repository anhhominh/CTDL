#include<iostream>

using namespace std;

void shellSort(int a[], int n){
	int interval, i, j,k, tmp;
	for(interval = n/2;interval > 0; interval /=2){
		for(j=interval;j<n;j++){
			for(k=j-interval;k>=0;k-=interval){
				if(a[k+interval]>=a[k]){
				break;
				} else {
					tmp = a[k+interval];
					a[k+interval] = a[k];
					a[k] = tmp;
				}
			}
		}
	}
}
int main(){
	int a[100001],n,i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	shellSort(a,n);
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}