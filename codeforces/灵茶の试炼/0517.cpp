// https://codeforces.com/problemset/problem/1693/B
// 1700 2023-05-17

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
    int n; cin >> n;
    vector<int> p(n+1);
    vector<vector<int>> s(n+1), lr(n+1, vector<int>(2));
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        s[p[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        cin >> lr[i][0] >> lr[i][1];
    int ans = 0;
    function<LL(int)> dfs = [&](int u) {
        LL sum = 0;
        for (int v : s[u])
            sum += dfs(v);
        if (sum < lr[u][0]) {
            ans += 1;
            sum = lr[u][1];
        }
        else if (sum > lr[u][1]) {
            sum = lr[u][1];
        }
        return sum;
    };
    dfs(1);
    cout << ans << endl;
}

int main() {

#ifdef debug
    // ifstream cin("../../in.txt");
    // ofstream cout("../../out.txt");
    freopen("../../in.txt", "r", stdin);
    freopen("../../out.txt", "w", stdout);
#endif

    int T = 1;
    scanf("%d", &T);
    while (T--) solve();

    return 0;
}