class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (isok(i)) ans += i * i;
        return ans;
    }

    bool isok(int x) {
        string s = to_string(x * x);
        bool res = false;
        function<void(int,int)> dfs = [&](int i, int sum) {
            if (i == s.size()) {
                if (sum == x) res = true;
                return;
            }
            int t = 0;
            for (int j = i; j < s.size(); j++) {
                t = t * 10 + s[j] - '0';
                dfs(j+1, sum + t);
            }
        };
        dfs(0, 0);
        return res;
    }
};