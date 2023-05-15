class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (auto &d : details)
            ans += d.substr(11, 2) > "60";
        return ans;
    }
};