class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int i = 0;
        size_t it = 0;
        unordered_map<char, string> m;
        unordered_map<string, char> m2;
        while (it != string::npos && i < pattern.size()) {
            auto next = str.find(' ', it);
            string sub;
            if (next == string::npos) sub = str.substr(it);
            else sub = str.substr(it, next - it);

            if (m.find(pattern[i]) == m.end() && m2.find(sub) == m2.end()) {
                m2[sub] = pattern[i];
                m[pattern[i++]] = sub;
            } else {
                if (m2[sub] != pattern[i] || sub != m[pattern[i]]) {
                    return false;
                }
                i++;
            }
            if (next != string::npos) it = next + 1;
            else it = next;
        }
        return it == string::npos && i == pattern.size();
    }
};
