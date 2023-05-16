class Solution {
public:
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        if (n < d) return -1;
        vector<vector<int>> mx(n+1, vector<int>(n+1));
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++)
                mx[i][j] = max(mx[i][j-1], jd[j-1]);
        vector<vector<int>> dp(d+1, vector<int>(n+1, 0x3f3f3f3f));
        dp[0][0] = 0;
        for (int i = 1; i <= d; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 0; k < j; k++)
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + mx[k+1][j]);
        return dp[d][n];
    }
};

class Solution {
public:
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        if (n < d) return -1;
        vector<vector<int>> mx(n+1, vector<int>(n+1));
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++)
                mx[i][j] = max(mx[i][j-1], jd[j-1]);
        vector<int> dp(n+1, 0x3f3f3f3f);
        dp[0] = 0;
        for (int i = 1; i <= d; i++)
            for (int j = n; j >= i; j--) {
                dp[j] = 0x3f3f3f3f;
                for (int k = i-1; k < j; k++)
                    dp[j] = min(dp[j], dp[k] + mx[k+1][j]);
            }
        return dp[n];
    }
};