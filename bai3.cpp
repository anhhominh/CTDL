#include <iostream>
using namespace std;

int main(){
    int n,a[100],i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        a[i]=a[i]*a[i];
    }
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}