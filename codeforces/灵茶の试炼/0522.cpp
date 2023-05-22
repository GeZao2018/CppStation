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
    int n, m, q; cin >> n >> m;
    // int p[m+1][n+1];
    vector<vector<int>> p(m+1, vector<int>(n+1));
    for (int i = 1; i <= m; i++)
        for (int j = 0; j <= n; j++)
            p[i][j] = j;
    function<int(int,int)> find = [&](int c, int x) {
        if (p[c][x] != x) p[c][x] = find(c, p[c][x]);
        return p[c][x];
    };
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        int pa = find(c, a), pb = find(c, b);
        if (pa != pb) p[c][pa] = pb;
    }
    cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        int res = 0;
        for (int i = 1; i <= m; i++) {
            if (find(i, u) == find(i, v))
                res++;
        }
        cout << res << endl;
    }
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