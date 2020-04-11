class Solution {
public:
    vector<string> addOperators(string num, int target) {
        tar = target;
        calc(num, 0, 0, 0, ' ', "");
        return v;
    }
    
private:
    int tar;
    vector<string> v;
    void calc(string& num, int start, long res, long preval, char op, string curr) {
        if (start == num.length() && res == tar) {
            v.push_back(curr);
            return;
        }
        
        for (int len = 1; start + len <= num.length(); len++) {
            string sub = num.substr(start, len);
            if (len > 1 && sub[0] == '0') continue;
            long val = stol(sub);
            if (start == 0) {
                calc(num, start + len, val, val, '+', sub);
                continue;
            }
            calc(num, start + len, res + val, val, '+', curr + "+" + sub);
            calc(num, start + len, res - val, -val, '-', curr + "-" + sub);
            calc(num, start + len, res - preval + preval * val, preval * val, '*', curr + "*" + sub);
        }
    }
};
