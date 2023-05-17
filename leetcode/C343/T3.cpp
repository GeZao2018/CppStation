class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& sp) {
        using LL = long long;
        LL s = (LL)start[0] << 32 | start[1];
        LL t = (LL)target[0] << 32 | target[1];
        unordered_map<LL, int> dist;
        dist[t] = INT_MAX, dist[s] = 0;
        unordered_set<LL> vis;
        while (true) {
            LL u = -1, ud = -1;
            for (auto &[v, d] : dist) {
                if (!vis.count(v) && (ud < 0 || d < ud))
                    u = v, ud = d;
            }
            if (u == t) return ud;
            vis.insert(u);
            int x = u >> 32, y = u & UINT_MAX;
            dist[t] = min(dist[t], (int)ud + target[0]+target[1]-x-y);
            for (auto &s : sp) {
                int ds = ud + abs(s[0]-x)+abs(s[1]-y) + s[4];
                LL v = (LL)s[2] << 32 | s[3];
                if (!dist.count(v) || ds < dist[v])
                    dist[v] = ds;
            }
        }
        return -1;
    }
};