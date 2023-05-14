class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        function<int(int,int,int)> dfs = [&](int x, int y, int num) {
            if (grid[x][y] <= num) return 0;
            if (y == n-1) return 1;
            if (memo[x][y]) return memo[x][y];
            int res = 0;
            for (int i = max(0, x-1); i < min(m, x+2); i++) {
                res = max(res, dfs(i, y+1, grid[x][y]));
            }
            return memo[x][y] = res+1;
        };
        int ans = 0;
        for (int i = 0; i < m; i++)
            ans = max(ans, dfs(i, 0, 0));
        return ans - 1;
    }
};

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> f(m, vector<int>(n));
        for (int j = n-2; j >= 0; j--)
            for (int i = 0; i < m; i++)
                for (int k = max(0, i-1); k <= min(m-1, i+1); k++)
                    if (grid[k][j+1] > grid[i][j])
                        f[i][j] = max(f[i][j], f[k][j+1] + 1);
        int ans = 0;
        for (int i = 0; i < m; i++)
            ans = max(ans, f[i][0]);
        return ans;
    }
};