class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int mx = 0, ans = 0;
        function<void(int, int)> dfs = [&](int rt, int sum) {
            int l = rt * 2, r = rt * 2 + 1;
            if (l > n) {
                mx = max(mx, sum);
                return;
            }
            dfs(l, sum + cost[l-1]);
            dfs(r, sum + cost[r-1]);
        };
        dfs(1, cost[0]);
        function<int(int,int)> dfs2 = [&](int root, int sum) {
            int l = root*2, r = root*2 + 1;
            sum -= cost[root-1];
            if (l > n) {
                return sum;
            }
            int lc = dfs2(l, sum), rc = dfs2(r, sum);
            ans += abs(lc - rc);
            return min(lc, rc);
        };
        ans += dfs2(1, mx);
        return ans;
    }
};

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        for (int i = n/2; i > 0; i--) {
            int l = i*2, r = i*2+1;
            ans += abs(cost[l-1] - cost[r-1]);
            cost[i-1] += max(cost[l-1], cost[r-1]);
        }
        return ans;
    }
};