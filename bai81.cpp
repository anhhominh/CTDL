bool b[100001];
int c[100001];
bool a[1001][1001];
bool kt = false;

int bfs(int u, int v, int n){
   // int kq = n+1;
    queue<int> q;
    q.push(u);
    b[u] = false;
    while(!q.empty()){
        int k = q.front();
        for(int i = 1; i <= n; i++){
            if(a[k][i] && b[i]){
                c[i] = c[k] + 1;
                b[i] = false;
                q.push(i);
                if( i == v) break;
            }
        }
        q.pop();
    }
    return c[v];
}
int graphFunction(int n, std::vector<std::vector<int>> e, int u, int v)
{
    for(int i=0; i<=n; i++){
        b[i] = true;
        c[i] = 0;
    }
    for( int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            a[i][j] = false;
        }
    }
    for( int i=0; i<e.size(); i++){
        a[e[i][0]][e[i][1]] = true;
        a[e[i][1]][e[i][0]] = true;
    }
    int k = bfs(u,v,n);
    return (k==0) ? -1 : k;
}