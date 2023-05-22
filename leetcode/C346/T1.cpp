class Solution {
public:
    int minLength(string s) {
        while (true) {
            bool flag = false;
            for (int i = 0; i+1 < s.size(); i++) {
                string t = s.substr(i, 2);
                if (t == "AB" || t == "CD") {
                    s = s.substr(0, i) + s.substr(i+2);
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            else break;
        }
        return s.size();
    }
};


class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for (char c : s) {
            if (!st.empty()) {
                if (c == 'B' && st.top() == 'A') st.pop();
                else if (c == 'D' && st.top() == 'C') st.pop();
                else st.push(c);
            } else {
                st.push(c);
            }
        }
        return st.size();
    }
};