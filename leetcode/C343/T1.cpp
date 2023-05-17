class Solution {
public:
    int isWinner(vector<int>& p1, vector<int>& p2) {
        int n = p1.size(), c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
            if (i && p1[i-1] == 10) c1 += p1[i]*2;
            else if (i>1 && p1[i-2] == 10) c1 += p1[i]*2;
            else c1 += p1[i];
            if (i && p2[i-1] == 10) c2 += p2[i]*2;
            else if (i>1 && p2[i-2] == 10) c2 += p2[i]*2;
            else c2 += p2[i];
        }
        if (c1 > c2) return 1;
        if (c2 > c1) return 2;
        return 0;
    }
};