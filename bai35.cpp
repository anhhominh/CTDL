#include<iostream>

using namespace std;

int main(){
	int a[100],n,i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
    bool kt = true;
	for(i=0;i<n;i++){
		if(i%2==0&&a[i]%2!=0){
			cout<<a[i]<<" ";
            kt = false;
		}
	}
    if(kt)cout<<"NULL";
	return 0;
}