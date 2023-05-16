class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& q) {
        int m = q.size();
        vector<int> a(n), ans(m);
        for (int j = 0; j < m; j++) {
            int i = q[j][0], c = q[j][1];
            int cnt1 = 0, cnt2 = 0;
            if (a[i]) {
                if (i) cnt1 += a[i] == a[i-1];
                if (i < n-1) cnt1 += a[i] == a[i+1];
            }
            a[i] = c;
            if (i) cnt2 += a[i] == a[i-1];
            if (i < n-1) cnt2 += a[i] == a[i+1];
            if (j) ans[j] = ans[j-1] - cnt1 + cnt2;
            else ans[j] = cnt2 - cnt1;
            // cout << cnt1 << " " << cnt2 << endl;
        }
        return ans;
    }
};