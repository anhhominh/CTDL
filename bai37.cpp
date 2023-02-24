#include<iostream>

using namespace std;
int BinSearch(int a[],int n,int x){
	int l=0,r=n-1;
	while(l<r){
		int mid = (l+r)/2;
		if(a[mid] < x ){
			l=mid+1;
		}else {
			r = mid;
		}
	}
	if(a[l]==x)return l;
	return -1;
}
int main(){
	int a[100],n,x,i,k=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>x;
	cout<< BinSearch(a,n,x);
	return 0;
}