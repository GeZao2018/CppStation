class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        vector<long long> s(n+1), ans;
        for (int i = 0; i < n; i++) s[i+1] = s[i] + nums[i];
        for (long long q : queries) {
            if (q <= nums[0]) ans.push_back(s[n] - n*q);
            else if (q >= nums[n-1]) ans.push_back(n*q - s[n]);
            else {
                int t = lower_bound(nums.begin(), nums.end(), q) - nums.begin();
                ans.push_back(t*q - s[t] + s[n]-s[t] - (n-t)*q);
            }
        }
        return ans;
    }
};