class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size(), MOD = 1e9 + 7;
        int f[target+1]; memset(f, 0, sizeof f);
        f[0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = target; j >= 0; j--)
                for (int k = 1; k <= types[i][0]; k++)
                    if (j >= types[i][1] * k)
                        f[j] = (f[j] + f[j - types[i][1]*k]) % MOD;
        return f[target];
    }
};