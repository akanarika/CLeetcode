class Solution {
public:
    int minAddToMakeValid(string S) {
        int left = 0;
        int right = 0;
        for (const auto& c : S) {
            if (c == '(') {
                left++;
            } else {
                if (left > 0) left--;
                else {
                    right++;
                }
            }
        }
        return left + right;
    }
};
