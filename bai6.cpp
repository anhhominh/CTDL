#include <iostream>
#include<math.h>
using namespace std;
int nguyento(int n){
    if(n<2)return 0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return 0;
    }
    return 1;
}
int main(){
    int n,a[100],i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        if(nguyento(a[i])==1)cout<<a[i]<<" ";
    }
    return 0;
}