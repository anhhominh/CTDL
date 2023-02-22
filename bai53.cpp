#include<iostream>

using namespace std;

long long luythua(int a,int b){
	if(b==0)return 1;
	return a * luythua(a,b-1);
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<< luythua(a,b);
	return 0;	
}