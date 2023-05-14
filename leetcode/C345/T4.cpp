class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> p(n), d(n);
        for (int i = 0; i < n; i++) p[i] = i;
        function<int(int)> find = [&](int x) {
            if (p[x] != x) p[x] = find(p[x]);
            return p[x];
        };
        for (auto &e : edges) {
            p[find(e[0])] = find(e[1]);
            d[e[1]]++, d[e[0]]++;
        }
        vector<vector<int>> m(n);
        for (int i = 0; i < n; i++)
            m[find(i)].push_back(i);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0, sz = m[i].size();
            if (sz == 0) continue;
            for (auto u : m[i]) cnt += d[u];
            ans += cnt == sz * (sz-1);
        }
        return ans;
    }
};