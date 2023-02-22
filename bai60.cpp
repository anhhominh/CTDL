#include<iostream>
using namespace std;
void deQuy(int n, int j, int k, string s){
    if(k==0) cout << s << " ";
    else{
        for(int i=j; i<=n; i++){
        deQuy(n, i+1, k-1, s+char(i+'0'));            
        }
    }
}
int main(){
    int n, k;
    cin >> n >> k;
    deQuy(n, 1, k, "");
    return 0;
}