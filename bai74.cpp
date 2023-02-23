/*
Cho dãy số nguyên a gồm n số nguyên. Tìm dãy con dài nhất không giảm trong a, 
nếu có nhiều dãy con dài nhất thì chọn lần xuất hiện đầu tiên.
*/

#include<iostream>

using namespace std;

int main(){
	int n,a[100001],l[100001];
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	l[0] = 1;
	for(int i = 0 ; i < n ; i++){
		if(a[i]>=a[i-1]){
			l[i] = l[i-1] + 1;
		} else l[i] = 1;
	}
	
	int csMax = 0;
	for(int i = 0 ; i < n ; i++){
		if(l[csMax] < l[i]){
			csMax = i;
		}
	}
	for(int i = csMax - l[csMax] + 1; i<= csMax; i ++){
		cout << a[i] << " ";
	}
	return 0;
}