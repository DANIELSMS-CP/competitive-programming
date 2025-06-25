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

void solve()
{
    int a1,a2;
    cin >> a1 >> a2;
    int b1,b2;
    cin >> b1 >> b2;
    bool s=0;
    if(b2>a2)
    {
        s=1;
        swap(b1,a1);
        swap(b2,a2);
    }
    a2-=b2;
    b2=0;
    if(a2==b2)
    {
        if(a1>b1 or (a1<b1 and s))
        {
            cout << ">\n";
        }
        else if(a1<b1 or (a1>b1 and s))
        {
            cout << "<\n";
        }
        else
        {
            cout << "=\n";
        }
    }
    else
    {
        string ss=to_string(a1),ss2=to_string(b1);
        int diff=sz(ss)-sz(ss2);
        // debug(diff)
        if(diff>0)
        {
            if(s)
            {
                cout << "<\n";
            }
            else
            {
                cout << ">\n";
            }
        }
        else if(diff<=0)
        {
            diff=abs(diff);
            if(diff<a2)
            {
                if(s)
                {
                    cout << "<\n";
                }
                else
                {
                    cout << ">\n";
                }
            }
            else if(diff==a2)
            {
                for(int i=0;i<sz(ss);i++)
                {
                    if(ss[i]>ss2[i])
                    {
                        if(s)
                        {
                            cout << "<\n";
                        }
                        else
                        {
                            cout << ">\n";
                        }
                        return;
                    }
                    else if(ss[i]<ss2[i])
                    {
                        if(s)
                        {
                            cout << ">\n";
                        }
                        else
                        {
                            cout << "<\n";
                        }
                        return;
                    }
                }
                for(int i=sz(ss);i<sz(ss2);i++)
                {
                    if(ss2[i]>'0')
                    {
                        if(s)
                        {
                            cout << ">\n";
                        }
                        else
                        {
                            cout << "<\n";
                        }
                        return;
                    }
                }
                cout << "=\n";
            }
            else
            {
                if(s)
                {
                    cout << "<\n";
                }
                else
                {
                    cout << ">\n";
                }
            }
        }
    }
}
signed main()
{
    fastio();
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}