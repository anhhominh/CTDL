#include<iostream>

using namespace std;

int choose(int a[], int n){
    int s[100001][2];
    for( int i = 0; i < n; i++){
        s[i][0] = a[i];// tổng lớn nhất với lượt chọn lẻ kết thúc tại i
        s[i][1] = -1;// tổng lớn nhát với lượt chọn chẵn kết thúc tại i
    }
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if(a[j] == a[i] && s[j][0] + a[i] > s[i][1]) s[i][1] = s[j][0] + a[i];
        }
        for (int j = 0; j < i; j++){
            if(s[j][1] + a[i] > s[i][0]) s[i][0] = s[j][1] + a[i];
        }
    }
    int max = -1;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) 
        if(s[i][j]>max) max = s[i][j];
    }
    return max;
}
int main(){
    int a[100001],n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << choose(a,n);
    return 0;
}