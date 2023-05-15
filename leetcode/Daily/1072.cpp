class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int t = (n + 31) / 32;
        vector<vector<vector<int>>> rows(m);
        for (int i = 0; i < m; i++) {
            vector<int> a(t), b(t);
            for (int j = 0; j < n; j++) {
                if (mat[i][j]) b[j/32] |= (1 << (j%32));
                else a[j/32] |= (1 << (j%32));
            }
            rows[i].emplace_back(a);
            rows[i].emplace_back(b);
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            vector<int> c = rows[i][0];
            int cnt = 0;
            for (int j = 0; j < m; j++) 
                cnt += c == rows[j][0] || c == rows[j][1];
            ans = max(ans, cnt);
        }
        return ans;
    }
};



class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        int ans = 0, n = mat[0].size();
        unordered_map<string, int> cnt;
        for (auto& row : mat) {
            string r(n, 0);
            for (int i = 0; i < n; i++)
                r[i] = row[i] ^ row[0];
            ans = max(ans, ++cnt[r]);
        }
        return ans;
    }
};