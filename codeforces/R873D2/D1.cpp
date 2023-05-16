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
const int N = 5005;

int n, a[N], f[N][N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            f[i][j] = 0;
    for (int l = 1; l < n; l++)
        for (int i = 0; i + l < n; i++) {
            int j = i + l;
            if (a[i] > a[j]) f[i][j] = l;
            else f[i][j] = f[i][j-1] + f[i+1][j] - f[i+1][j-1];
        }
    LL ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            ans += f[i][j];
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