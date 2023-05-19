class Solution {
public:
    int numTilePossibilities(string tiles) {
        int cnt[26] = {0};
        for (char ch : tiles) cnt[ch-'A']++;
        function<int()> dfs = [&]() {
            int res = 0;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] > 0) {
                    ++res;
                    --cnt[i];
                    res += dfs();
                    ++cnt[i];
                }
            }
            return res;
        };
        return dfs();
    }
};



const int MX = 8;
int c[MX][MX];

int init = []() {
    for (int i = 0; i < MX; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = c[i-1][j-1] + c[i-1][j];
    }
    return 0;
}();

class Solution {
public:
    int numTilePossibilities(string tiles) {
        int cnt[26] = {0};
        for (char c: tiles) cnt[c-'A']++;
        int n = tiles.size();
        int f[27][n+1]; memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= 26; i++) {
            for (int j = 0; j <= n; j++)
                for (int k = 0; k <= j && k <= cnt[i-1]; k++)
                    f[i][j] += f[i-1][j-k] * c[j][k];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) ans += f[26][i];
        return ans;
    }
};



const int MX = 8;
int c[MX][MX];

int init = []() {
    for (int i = 0; i < MX; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = c[i-1][j-1] + c[i-1][j];
    }
    return 0;
}();

class Solution {
public:
    int numTilePossibilities(string tiles) {
        int cnt[26] = {0};
        for (char c: tiles) cnt[c-'A']++;
        int n = tiles.size();
        int f[n+1]; memset(f, 0, sizeof f);
        f[0] = 1;
        for (int i = 1; i <= 26; i++) {
            for (int j = n; j >= 0; j--)
                for (int k = 1; k <= j && k <= cnt[i-1]; k++)
                    f[j] += f[j-k] * c[j][k];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) ans += f[i];
        return ans;
    }
};