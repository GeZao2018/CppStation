class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int ans = 0, s = 0;
        for (long long x : nums) {
            ans = (ans + x * x % MOD * (x + s)) % MOD;
            s = (s * 2 + x) % MOD;
        }
        return ans;
    }
};