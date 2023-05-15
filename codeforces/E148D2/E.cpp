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
const int MOD = 998244353;
const int N = 200010;

void solve() {
    int n, a1, x, y, m, k;
    cin>>n>>a1>>x>>y>>m>>k;
    vector<LL> a(n+1);
    a[1] = a1;
    for (int i = 2; i <= n; i++) {
        a[i] = (a[i-1] * x + y) % m;
    }
    for (int j = 0; j <= k; j++) {
        for (int i = 2; i <= n; i++)
            a[i] = (a[i] + a[i-1]) % MOD;
    }
    LL ans = 0;
    for (int i = k; i <= n; i++)
        ans ^= a[i-k+1] * i;
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
    // scanf("%d", &T);
    while (T--) solve();

    return 0;
}