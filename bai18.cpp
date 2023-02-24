#include<iostream>
#include<queue>
#include<math.h>

using namespace std;

bool nguyento(int n){
    if(n<2)return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return false;
    }
    return true;
}

int main(){
    queue<int> q;
    int n;
    cin>>n;
    for(int i=2;i<n,i<10;i++){
        if(nguyento(i))q.push(i);
    }

    while(!q.empty()){
        for(int i=1;i<=9;i++){
          int k=q.front()*10+i;
          if(k<=n && nguyento(k))q.push(k);
        }
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}