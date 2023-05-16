class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n+1), ans(n);
        set<int> st;
        for (int i = n-1; i >= 0; i--) {
            st.insert(nums[i]);
            cnt[i] = st.size();
        }
        st.clear();
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
            ans[i] = st.size() - cnt[i+1];
        }
        return ans;
    }
};