class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](auto &a, auto &b) {
            return (a[1]-a[0]) > (b[1]-b[0]);
        });
        int ans = 0, cost = 0;
        for (auto &t : tasks) {
            if (cost < t[1]) {
                ans += t[1] - cost;
                cost = t[1];
            }
            cost -= t[0];
        }
        return ans;
    }
};