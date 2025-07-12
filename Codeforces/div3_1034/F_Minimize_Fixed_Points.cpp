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

vector<int> primes;
void pre()
{
    int n=1e5;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for(int i=0;i<=n;i++)
    {
        if(is_prime[i])
        {
            primes.push_back(i);
        }
    }
}
vector<long long> trial_division4(long long n) {
    vector<long long> factorization;
    for (long long d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}
void solve()
{
    int n;
    cin >> n;
    map<int,vector<int>> v;
    for(int i=2;i<=n;i++)
    {
        vector<int> a=trial_division4(i);
        v[a.back()].push_back(i);
    }
    cout << "1 ";
    vector<int> ans(n+5);
    for(auto [i,val]:v)
    {
        for(int j=1;j<=sz(v[i]);j++)
        {
            ans[v[i][(j-1)%sz(v[i])]-1]=v[i][(j)%sz(v[i])];
        }
    }
    for(int i=1;i<n;i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
signed main()
{
    fastio();
    pre();
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}