// just want to submit this
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p, k;
    cin >> n >> p >> k;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<vector<int>> s(n, vector<int>(p));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> s[i][j];
        }
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);

    sort(ord.begin(), ord.end(), [&](int x, int y) {
        return a[x] > a[y];
    });

    const int NEG = -(1LL << 60);

    vector<int> dp(1 << p, NEG);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        int id = ord[i];
        vector<int> ndp = dp;

        for (int mask = 0; mask < (1 << p); mask++) {
            if (dp[mask] == NEG) continue;

            int cnt = __builtin_popcount(mask);

            if (i - cnt < k) {
                ndp[mask] = max(ndp[mask], dp[mask] + a[id]);
            }

            for (int j = 0; j < p; j++) {
                if (!(mask & (1 << j))) {
                    int nmask = mask | (1 << j);
                    ndp[nmask] = max(ndp[nmask], dp[mask] + s[id][j]);
                }
            }
        }

        dp.swap(ndp);
    }

    cout << dp[(1 << p) - 1] << '\n';
}