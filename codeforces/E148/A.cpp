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
const int N = 55;

char s[N];

void solve() {
    scanf("%s", s);
    int n = strlen(s);
    int vis = 0, cnt = 0;
    for (int i = 0; i < n/2; i++) {
        if ((vis >> s[i] - 'a') ^ 1) cnt++;
        vis |= 1 << (s[i] - 'a');
    }
    if (cnt > 1) puts("YES");
    else puts("NO");
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