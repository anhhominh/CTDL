#include<iostream>
using namespace std;

string chuoidoixung(string s, int x, int y){
    if(x>y) return "";
    string a;
    a=s[x];
    if(x==y) return a;
    for(int i=x; i<y; i++)
    {
        string b;
        for(int j=i+1; j<=y; j++)
            if(s[j]==s[i])
            {
                b=s[i]+chuoidoixung(s,i+1,j-1)+s[j];
                if(b.size()>a.size()) a=b;
            } 
    }
    return a;
}

int main(){
    string s;
    getline(cin, s);
    cout<<chuoidoixung(s,0,s.size()-1);
    return 0;
}