#include<iostream>
using namespace std;

int main(){
    int n,k,i,a[100];
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>k;
    for(i=k;i<n;i++){
        a[i]=a[i+1];
    }
    n--;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}