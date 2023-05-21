// https://codeforces.com/contest/786/problem/C
// 2400

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define fir first 
#define sec second
#define LL long long
#define LD long double
#define ULL unsigned long long
#define PII pair<int, int>
#define PLL pair<long, long>
// #define debug

const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 200010;

void solve() {
    int n, clock = 0; cin >> n;
    int a[n], time[n+1]; memset(time, 0, sizeof(time));
    for (int i = 0; i < n; i++) cin >> a[i];
    auto func = [&](int k) -> int {
        clock++;
        int left = 0, res = 0;
        for (int i = 0; i < n; i++) {
            if (time[a[i]] == clock) continue;
            if (left == 0) res++, clock++, left = k;
            time[a[i]] = clock, left--;
        }
        return res;
    };
    int ans[n+1];
    function<void(int, int)> dfs = [&](int l, int r) {
        if (l > r) return;
        ans[l] = func(l), ans[r] = func(r);
        if (ans[l] == ans[r]) {
            for (int i = l+1; i < r; i++) ans[i] = ans[l];
            return;
        }
        int mid = l + r >> 1;
        dfs(l+1, mid); dfs(mid+1, r-1);
    };
    dfs(1, n);
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}

int main() {

#ifdef debug
    // ifstream cin("../../in.txt");
    // ofstream cout("../../out.txt");
    freopen("../../in.txt", "r", stdin);
    freopen("../../out.txt", "w", stdout);
#endif

    int T = 1;
    // scanf("%d", &T);
    // cin >> T;
    while (T--) solve();

    return 0;
}