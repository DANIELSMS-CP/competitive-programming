struct DSU
{
    vector<int> par,sz;
    DSU(int n)
    {
        par.resize(n+1,0);
        sz.resize(n+1,1);
        for(int i=1;i<=n;i++)
        {
            par[i]=i;
        }
    }
    int find_par(int u)
    {
        return par[u]=(u==par[u]?u:find_par(par[u]));
    }
    bool merge(int a,int b)
    {
        int x=find_par(a);
        int y=find_par(b);
        if(x==y)
        {
            return false;
        }
        if(sz[x]>sz[y])
        {
            swap(x,y);
        }
        par[x]=y;
        sz[y]+=sz[x];
        return true;
    }
};