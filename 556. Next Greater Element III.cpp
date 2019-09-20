class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.length() - 1;
        while (i >= 0) {
            int lastIdx = s.length();
            for (int j = i + 1; j < s.length(); j++) {
                if ((s[j] > s[i]) && (lastIdx == s.length() || (s[lastIdx] > s[j]))) {
                    lastIdx = j;
                }
            }
            if (lastIdx != s.length()) {
                char tmp = s[lastIdx];
                s[lastIdx] = s[i];
                s[i] = tmp;
                sort(s.begin() + i + 1, s.end());
                if (s.length() == to_string(INT_MAX).length()) {
                    int k = 0;
                    for (auto c : to_string(INT_MAX)) {
                        if (s[k++] > c) return -1;
                    }
                }
                return stoi(s);
            }
            i--;
        }

        return -1;
    }
};
