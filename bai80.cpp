bool b[100001];
bool a[1001][1001];
bool kt = false;
void dfs(int u, int v, int n){
    b[u] = false;
    for (int i = 1; i <= n; i++){
        if (a[u][i] && b[i]){
            if (i == v){
                kt = true;
            }
            dfs(i, v, n);
            b[i] = true;
        }
    }
}
bool check(int n, std::vector<std::vector<int>> e, int u, int v)
{
    for(int i = 0; i <= n; i++){
        b[i] = true;
    }

    for( int i = 1; i <= n; i++){
        for(int j = 1; j<= n; j++){
            a[i][j] = false;
        }
    }

    for(int i = 0; i < e.size(); i++){
        a[e[i][0]][e[i][1]] = true;
    }
    dfs(u,v,n);
    return kt;
}