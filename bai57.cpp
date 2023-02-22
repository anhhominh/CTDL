#include<iostream>

using namespace std;

int dem(int n,int k){
	if(k==0)return 1;
	if( (n-1)%3 == 0 && ((n-1)/3)%2 != 0 ){
		return dem(2*n,k-1) + dem((n-1)/3,k-1);
	}
	return dem(2*n,k-1);
}
int main(){
	int n,k;
	cin>>n>>k;
	cout<<dem(n,k);
	return 0;
}