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
#define debug

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 300010;

int a[N], n, m, b;

void solve() {
    scanf("%d", &n);
    m = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &b);
        if (m && b == a[m-1]) continue;
        a[m++] = b;
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (i == 0 || i == m-1 || (a[i] > a[i-1]) == (a[i] > a[i+1]))
            ans ++ ;
    }
    printf("%d\n", ans);
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