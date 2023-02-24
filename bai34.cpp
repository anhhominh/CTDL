#include<iostream>

using namespace std;

int main(){
	int a[100],n,i,x;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>x;
	int dem = 0;
	for(i=0;i<n;i++){
		if(a[i]==x){
			dem++;
		}
	}
	cout<<dem;
	return 0;
}