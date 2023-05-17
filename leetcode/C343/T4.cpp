class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int n = s.size(), i = n-1;
        k += 'a', s[i]++;
        while (i < n) {
            if (s[i] == k) {
                if (i == 0) return "";
                s[i] = 'a';
                ++s[--i];
            }
            else if ((i && s[i-1] == s[i]) || (i>1 && s[i-2] == s[i])) {
                ++s[i];
            }
            else ++i;
        }
        return s;
    }
};