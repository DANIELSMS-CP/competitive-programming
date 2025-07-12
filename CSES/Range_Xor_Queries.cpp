//and in that light, I find deliverance
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
//defines
#define int long long
#define debug(x) cerr << "(" << #x << "=" << x << "," << __LINE__ << ")\n";
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rep(i,a,b) for(int i=a;i<(b);i++)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
 
//constants
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1}; 
const char dir[4]{'D','R','U','L'};
const int MOD=1e9+7;
const int maxn=2e5+5;
const double eps=1e-9;
 
//typedefs
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
 
//Template
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
//Mods
int add(int a, int b) 
{
    if((a+=b)>=MOD)
    {
        a-=MOD;
    }
    return a;
}
int sub(int a, int b) 
{
  if((a-=b)<0)
  {
        a+=MOD;
  }
  return a;
}
int mul(int a,int b) 
{
    int ret=(a%MOD*b%MOD)%MOD;
    if(ret<0)
    {
        ret+=MOD;
    }
    return ret;
}

struct node
{
    int s,e,m;
    int val;
    node *left,*right;
    node(int ss,int ee,vector<int> &a)
    {
        s=ss,e=ee;
        m=(s+e)/2;
        if(s==e)
        {
            val=a[e];
            return;
        }
        left=new node(s,m,a);
        right=new node(m+1,e,a);
        val=left->val^right->val;
    }
    void upd(int p,int v)
    {
        if(s==e)
        {
            val=v;
            return;
        }
        int m=(s+e)/2;
        if(p<=m)
        {
            left->upd(p,v);
        }
        else
        {
            right->upd(p,v);
        }
        val=left->val^right->val;
    }
    int qry(int l,int r)
    {
        if(l>e or r<s)
        {
            return 0;
        }
        if(l<=s and e<=r)
        {
            return val;
        }
        return left->qry(l,r)^right->qry(l,r);
    }
};
void solve()
{
    int n,q;
    cin >> n >> q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    node segtree(1,n,a);
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        cout << segtree.qry(l,r) << '\n';
    }
}
signed main()
{
    fastio();
    int t=1;
    // cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}