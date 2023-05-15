class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size();
        for (auto &row : nums)
            sort(row.begin(), row.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int mx = 0;
            for (int j = 0; j < m; j++)
                mx = max(mx, nums[j][i]);
            ans += mx;
        }
        return ans;
    }
};