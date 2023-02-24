#include<iostream>
using namespace std;

int main(){
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bool kt1=true, // kiểm tra dãy tăng
    bool kt2=true; // kiểm tra dãy giảm
    for(int i=1;i<n;i++){
        if(a[i]<=a[i-1])kt1=false;
        if(a[i]>=a[i-1])kt2=false;
    }
    if(kt1==true||kt2==true)cout<<"YES";
    else cout<<"NO";
    return 0;
}