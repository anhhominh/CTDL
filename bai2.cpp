#include <iostream>

using namespace std;

int main(){
    int n,a[100];
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>a[i];
    }

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    cout<< sum;
    return 0;
}