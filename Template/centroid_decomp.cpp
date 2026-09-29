int sub[maxn];
int cpar[maxn];
bool dead[maxn];
void dfs_sz(int u, int p)
{
    sub[u] = 1;
 
    for(int v : adjlist[u])
    {
        if(v == p || dead[v]) continue;
 
        dfs_sz(v, u);
        sub[u] += sub[v];
    }
}
 
int get_centroid(int u, int p, int tot, char c)
{
    for(int v : adjlist[u])
    {
        if(v == p || dead[v]) continue;
 
        if(sub[v] > tot / 2)
            return get_centroid(v, u, tot, c);
    }
    ans[u]=c;
    return u;
}
 
void build_centroid(int u, char cc, int p = -1)
{
    dfs_sz(u, -1);
 
    int c = get_centroid(u, -1, sub[u], cc);
 
    cpar[c] = p;
    dead[c] = true;
 
    for(int v : adjlist[c])
    {
        if(dead[v]) continue;
 
        build_centroid(v, cc+1, c);
    }
}

// call build_centroid(1,'A');