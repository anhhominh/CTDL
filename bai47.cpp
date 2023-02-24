#include<iostream>

using namespace std;

void bubbleSort(int a[],int n){
	for(int i=n-1;i>=1;i--){
		bool swapper = true;
		for(int j=0;j<i;j++){
			if(a[j]>a[j+1]){
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
				swapper = false;
			}
		}
		if(swapper)break;
	}
}

int solution(int a[],int n){
	bubbleSort(a,n);
	if(a[0]>0)return 0;
	for(int i=1;i<n;i++){
		if(a[i]-a[i-1]>1){
			return a[i-1]+1;
		}
	}
	return a[n-1] + 1;
}
int main(){
	int a[100],n,i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<solution(a,n);
	return 0;
}