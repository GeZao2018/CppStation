class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> dis(n);
        int ans = 0x3f3f3f3f;
        auto bfs = [&](int start) {
            fill(dis.begin(), dis.end(), -1);
            queue<pair<int,int>> q;
            q.push({start, -1});
            dis[start] = 0;
            while (q.size()) {
                auto [u, fa] = q.front();
                q.pop();
                for (int v : g[u]) {
                    if (dis[v] < 0) {
                        dis[v] = dis[u] + 1;
                        q.emplace(v, u);
                    }
                    else if (v != fa) {
                        ans = min(ans, dis[u] + dis[v] + 1);
                    }
                }
            }
        };
        for (int i = 0; i < n; i++) bfs(i);
        return ans == 0x3f3f3f3f ? -1 : ans;
    }
};