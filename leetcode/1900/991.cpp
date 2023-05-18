class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while (target != startValue) {
            if (target > startValue) {
                if (target & 1) target += 1;
                else target /= 2;
                ans += 1;
            } else {
                ans += startValue-target;
                target = startValue;
            }
        }
        return ans;
    }
};