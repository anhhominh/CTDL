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

int main(){
	int a[100001],n,i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	bubbleSort(a,n);
	int count = 1;
	for(i=1;i<n;i++){
		if(a[i]==a[i-1]){
			count++;
		} else {
			cout<< a[i-1] << " "<<count<<"; ";
			count = 1;
		}
	}
	cout<< a[n-1] << " " <<count<<"; ";
	return 0;
}