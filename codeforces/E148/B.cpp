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
const int MOD = 1e9 + 7;
const int N = 200010;

int a[N], n, k;
LL l[N], r[N];

void solve() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a+n);
    for (int i = 0; i < n/2; i++)
        l[i+1] = l[i] + a[i*2] + a[i*2+1];
    for (int i = 0; i < n; i++)
        r[i+1] = r[i] + a[n-1-i];
    LL ans = 0;
    for (int i = 0; i <= k; i++)
        ans = max(ans, r[n] - l[i] - r[k-i]);
    printf("%lld\n", ans);
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