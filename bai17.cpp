#include<iostream>
#include<queue>

using namespace std;

int main(){
	queue<int> q;
	int n,k,tmp;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp;
		q.push(tmp);
	}
	cin>>k;
	for(int i=0;i<k;i++){
		int x = q.front();
		q.pop();
		q.push(x);
	}
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	return 0;
}