class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> r(m), c(n);
        vector<pair<int,int>> midx(m*n+1);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                midx[mat[i][j]] = make_pair(i, j);
        for (int k = 0; k < arr.size(); k++) {
            auto [i, j] = midx[arr[k]];
            ++r[i], ++c[j];
            if (r[i] == n || c[j] == m)
                return k;
        }
        return -1;
    }
};