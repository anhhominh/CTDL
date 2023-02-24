#include<iostream>

using namespace std;

int main(){
	int a[100001],n,s,i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	int sum = 0;
	bool check = false;
	cin>>s;
	for(i=0;i<n;i++){
		sum = a[i];
		for(int j=i+1;j<n;j++){
			sum = sum + a[j];
			if(sum == s){
				for(int k=i;k<=j;k++){
				cout<<a[k]<<" ";	
				check = true;
				}
				break;
			}
		}	
		if(check){
			break;
		} 
	}
	if(check == false) cout<<"-1";
	return 0;
}