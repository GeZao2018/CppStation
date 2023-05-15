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
    vector<LL> a, backup(n);
    for (int i = 0; i < n; i++)
        cin >> backup[i];
    sort(backup.begin(), backup.end());
    while (q--) {
        cin >> k;
        a = backup;
        if (k <= n) {
            for (int i = 0; i < k; i++)
                a[i] += k - i;
            cout << *min_element(a.begin(), a.end()) << " ";
            continue;
        }
        for (int i = 0; i < n-1; i++)
            a[i] += k - i;
        if ((k-n+1) & 1) a[n-1] += k-n+1;
        k -= n-1; k /= 2;
        LL sum = 0, ans = LINF;
        for (int i = 0; i < n; i++) {
            ans = min(ans, (LL)a[i]);
            sum += a[i];
        }
        sum -= ans * n;
        if (sum < k) ans -= (k - sum + n-1) / n;
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