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
    LL n, q, k; cin >> n >> q;
    vector<LL> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    LL tot = accumulate(a.begin(), a.end(), 0LL);
    b[0] = a[0];
    for (int i = 1; i < n; i++) 
        b[i] = min(b[i-1], a[i] - i);
    while (q--) {
        cin >> k;
        if (k < n) {
            cout << min(b[k-1] + k, a[k]) << " ";
            continue;
        }
        LL ans = min(b[n-2] + k, a[n-1]);
        LL sum = tot - (n-1) * (n-2) / 2;
        sum += k * (n-1);
        if ((k-n+1) & 1) {
            sum += k - (n-1);
            ans = b[n-1] + k;
        }
        k -= n-1; k /= 2;
        sum -= ans * n;
        if (sum < k) ans -= (k-sum+n-1) / n;
        cout << ans << " ";
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
    while (T--) solve();

    return 0;
}