#include<iostream>
using namespace std;

int main(){
    int n,a[100],i,k,x;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>k>>x;
    for(i=n;i>=k+1;i--){
        a[i]=a[i-1];
    }
    a[k]=x;
    n++;
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}