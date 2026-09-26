// lazy to solve lol
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> getCost(const vector<int>& w) {
    int n = w.size();

    int totalW = 0;
    int totalKW = 0;

    for (int i = 0; i < n; i++) {
        totalW += w[i];
        totalKW += i * w[i];
    }

    vector<int> res(n);

    int prefW = 0;
    int prefKW = 0;

    for (int x = 0; x < n; x++) {
        // k < x
        int left = x * prefW - prefKW;

        // k > x
        int rightW = totalW - prefW - w[x];
        int rightKW = totalKW - prefKW - x * w[x];

        int right = rightKW - x * rightW;

        res[x] = left + right;

        prefW += w[x];
        prefKW += x * w[x];
    }

    return res;
}

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(N);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;

    int S = 2 * N - 1;

    vector<int> plus(S);
    vector<int> minus(S);

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            int people = A[r] * B[c] % M;

            plus[r + c] += people;
            minus[r - c + N - 1] += people;
        }
    }

    vector<int> costPlus = getCost(plus);
    vector<int> costMinus = getCost(minus);

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int u = i + j;
            int v = i - j + N - 1;

            int f = (costPlus[u] + costMinus[v]) / 2;

            ans ^= f + i * N + j;
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}