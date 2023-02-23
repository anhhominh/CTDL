/*
Anh Lộc làm nghề phụ hồ cho một công ty xây dựng, Anh nhận thấy rằng mỗi loại gạch đều có độ cứng khác nhau.
Giả sử rằng viên gạch có độ cứng k chỉ có thể chịu được tối đa k viên gạch khác chồng lên nó, nếu nhiều hơn thì nó sẽ bị vỡ.

Cho mảng a gồm n số nguyên dương lần lượt là độ cứng của các viên gạch.

Anh Lộc muốn lấy gạch và xếp chúng chồng lên nhau thành một chồng gạch cao nhất có thể mà không để vỡ viên gạch nào

Hãy tìm và in ra màn hình xem anh Lộc có thể xếp chồng gạch có độ cao lớn nhất là bao nhiêu.
*/

#include<iostream>
#include<algorithm>

using namespace std;

void quickSort(int a[], int l, int r){
	int p = a[(l+r)/2];
	int i = l , j = r;
	while( i < j ){
		while( a[i] < p ){
			i++;
		}
		while ( a[j] > p ){
			j--;
		}
		if ( i <= j ){
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}
	if(i<r) quickSort(a,i,r);
	if(j>l) quickSort(a,l,j);
}

int Solution(int a[], int n) {
    quickSort(a, 0, n - 1);

    int count = 1;
    int ans = a[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        count++;
        ans--;
        if (ans > a[i]) ans = a[i];
        if (ans == 0) return count;
    }
    return n;
}

int main(){
	int n,a[100001];
	cin>>n;
	for( int i=0;i<n;i++){
		cin >> a[i];
	}
  	cout << Solution(a, n) << endl;
    return 0;
}