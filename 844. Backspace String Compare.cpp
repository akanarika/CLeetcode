class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string ss;
        string ts;
        for (const auto& c : S) {
            if (c == '#') {
                if (!ss.empty()) ss.pop_back();
            } else ss.push_back(c);
        }
        for (const auto& c : T) {
            if (c == '#') {
                if (!ts.empty()) ts.pop_back();
            } else ts.push_back(c);
        }
        return ss == ts;
    }
};
