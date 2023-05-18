// https://codeforces.com/problemset/problem/1759/G
// 1900 2023-05-18

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
    int n; cin >> n;
    vector<int> b(n), pos(n+1);
    for (int i = 1; i < n; i += 2) {
        cin >> b[i];
        pos[b[i]] = i;
    }
    priority_queue<int> pq;
    for (int i = n; i > 0; i--) {
        if (pos[i]) pq.push(pos[i]);
        else if (pq.size()) {
            b[pq.top()-1] = i;
            pq.pop();
        }
        else {
            cout << "-1" << endl;
            return;
        }
    }
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << endl;
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
    cin >> T;
    while (T--) solve();

    return 0;
}