class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        int sum = 0, ans = 0;
        unordered_map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            sum += hours[i-1] > 8 ? 1 : -1;
            if (sum > 0) ans = max(ans, i);
            else {
                if (mp.count(sum-1))
                    ans = max(ans, i - mp[sum-1]);
                if (!mp.count(sum)) mp[sum] = i;
            }
        }
        return ans;
    }
};