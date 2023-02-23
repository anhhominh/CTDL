/*
Một người nông dân muốn trồng hoa trong vườn của mình. 
Để khu vườn thêm màu sắc, ông quyết định trồng nhiều loại hoa khác nhau trong vườn. 
Mỗi loài hoa có một cách trồng khác nhau nên ông sẽ trồng từng bông hoa vào những ngày liền nhau. 
Cháu trai của ông đã rất mong được nhìn thấy tất cả những bông hoa trong vườn nở rộ tuyệt vời như thế nào. 
Tuy nhiên, mỗi loài hoa có thời gian phát triển khác nhau từ khi trồng đến khi nở. 
Cho dãy a gồm n số nguyên dương lần lượt là thời gian phát triển của các bông hoa. 
Nhiệm vụ của bạn là giúp người nông dân tìm ra ngày hoa nở sớm nhất.
*/
#include<iostream>
#include<algorithm>

using namespace std;

void quickSort(int a[], int l, int r){
	int p = a[(l+r)/2];
	int i = l , j = r;
	while( i < j){
		while( a[i] < p){
			i++;
		}
		while( a[j] > p){
			j--;
		}
		if(i<=j){
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}
	if( i < r) quickSort(a,i,r);
	if( l < j ) quickSort(a,l,j);
}

int main() {
	int n,a[100];
	cin >> n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	quickSort(a,0,n-1);
	int k = 1;
	int max = 0;
	for(int i=n-1; i>=0; i--){
		if( a[i] + k > max){
			max = a[i] + k;
		}
		k++;
	}
	cout << max;
	return 0;
}