class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> vis(n);
        int i = 0, j = 1;
        while (vis[i] == 0) {
            vis[i] = 1;
            i = (i + j++ * k) % n;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (vis[i] == 0)
                ans.push_back(i+1);
        return ans;
    }
};