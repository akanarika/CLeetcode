class Solution {
public:
    int countBinarySubstrings(string s) {
        if (s.empty()) return 1;
        
        vector<int> contiguous;
        char last = s[0];
        int count = 1;
        for (int i = 1; i <= s.size(); i++) {
            if (i == s.size()) {
                contiguous.push_back(count);
            } else if (s[i] != last) {
                contiguous.push_back(count);
                last = s[i];
                count = 1;
            } else {
                count++; 
            }
        }
        
        int num = 0;
        for (int i = 1; i < contiguous.size(); i++) {
            num += min(contiguous[i], contiguous[i-1]);
            printf("%d,", count);
        } 
        
        return num;
    }
};