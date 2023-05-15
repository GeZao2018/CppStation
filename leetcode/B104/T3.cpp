class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int cnt[48]; memset(cnt, 0, sizeof cnt);
        long long sum = 0, ans = 0;
        for (int num : nums) {
            sum |= num;
            for (int i = 0; i < 32; i++)
                cnt[i] += (num >> i) & 1;
        }
        long long max_sum = sum;
        for (int i = 0; i < nums.size(); i++) {
            long long mx = sum;
            long long b = (long long)nums[i] << k, a = nums[i];
            int offset = 0;
            while (a) {
                if (a & 1) {
                    cnt[offset] -= 1;
                    if (cnt[offset] == 0) mx -= 1LL << offset;
                }
                a >>= 1; offset++;
            }
            offset = 0;
            while (b) {
                if (b & 1) {
                    if (cnt[offset] == 0) mx += 1LL << offset;
                }
                b >>= 1; offset++;
            }
            offset = 0, a = nums[i];
            while (a) {
                if (a & 1) cnt[offset] += 1;
                a >>= 1; offset++;
            }
            max_sum = max(max_sum, mx);
        }
        return max_sum;
    }
};

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size(), suf[n+1];
        suf[n] = 0;
        for (int i = n-1; i >= 0; i--)
            suf[i] = suf[i+1] | nums[i];
        long long ans = 0, pre = 0;
        for (int i = 0; i < n; i++) {
            long long cur = (long long)nums[i] << k;
            ans = max(ans, pre | cur | suf[i+1]);
            pre |= nums[i];
        }
        return ans;
    }
};