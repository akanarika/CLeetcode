class Solution {
public:
    int lengthLongestPath(string input) {
        if (input.empty()) return 0;
        stack<pair<int, int>> stk;
        int i = 0;
        int n = input.length();
        int maxlen = 0;
        while (i < n) {
            size_t next = input.find("\n", i);
            if (next == string::npos) next = n;
            int level = 0;
            while (i < next) {
                if (input.substr(i, 1) != "\t") break;
                level++;
                i++;
            }
            while (!stk.empty() && stk.top().first >= level) {
                stk.pop();
            }
            int len = next - i;
            bool isFile = (input.substr(i, len).find(".") != string::npos);
            if (!stk.empty() && stk.top().first == level - 1) {
                len += stk.top().second;
            }
            stk.push(make_pair(level, len + 1));
            if (isFile) maxlen = max(maxlen, len);
            if (next == string::npos) break;
            i = next + 1;
        }
        return maxlen;
    }
};
