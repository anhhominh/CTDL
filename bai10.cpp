#include<iostream>
using namespace std;

int main(){
    int m,n,a[100][100];
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int sum=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            sum = sum + a[i][j];
        }
    }
    cout<<sum;
    return 0;
}