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

int n, p[N];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int t = abs(p[i] - i);
        if (t == 0) continue;
        if (ans) ans = gcd(ans, t);
        else ans = t;
    }
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