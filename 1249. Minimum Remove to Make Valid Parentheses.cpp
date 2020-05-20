class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int left = 0;
        vector<int> toDel(s.length(), 0);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') left++;
            else if (s[i] == ')') {
                if (left > 0) left--;
                else {
                    toDel[i] = 1;
                }
            }
        }
        
        int right = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ')' && !toDel[i]) right++;
            else if (s[i] == '(') {
                if (right > 0) right--;
                else {
                    toDel[i] = 1;
                }
            }
        }
        
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            if (!toDel[i]) res += s[i];
        }
        return res;
    }
};
