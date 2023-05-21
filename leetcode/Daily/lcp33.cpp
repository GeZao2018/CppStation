class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int n = bucket.size();
        int m = 0, ans = 0x3f3f3f3f;
        for (int i = 0; i < n; i++) m = max(m, vat[i]);
        if (m == 0) return 0;
        for (int i = 1; i <= m; i++) {
            int k = 0;
            for (int j = 0; j < n; j++)
                k += max(0, (vat[j]-1)/i+1 - bucket[j]);
            ans = min(ans, i + k);
        }
        return ans;
    }
};

class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int n = bucket.size(), cnt = 0;
        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < n; i++) {
            if (!vat[i]) continue;
            if (!bucket[i]) cnt++, bucket[i]++;
            pq.emplace((vat[i]-1)/bucket[i]+1, i);
        }
        if (!pq.size()) return 0;
        int res = 0x3f3f3f3f;
        while (pq.size()) {
            auto [k, v] = pq.top(); pq.pop();
            res = min(res, k + cnt);
            bucket[v]++, cnt++;
            pq.emplace((vat[v]-1)/bucket[v]+1, v);
            if (cnt >= res) break;
        }
        return res;
    }
};