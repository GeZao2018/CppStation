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

int n, a[N], b[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a, a+n); sort(b, b+n);
    LL ans = 1, cnt = 0;
    for (int i = n-1; i >= 0; i--) {
        int l = 0, r = n-1;
        if (a[r] <= b[i]) {
            puts("0");
            return;
        }
        while (l < r) {
            int mid = l + r >> 1;
            if (a[mid] > b[i]) r = mid;
            else l = mid + 1;
        }
        // if (n-l <= cnt) {
        //     puts("0");
        //     return;
        // }
        ans = ans * (n-l-cnt) % MOD;
        cnt += 1;
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