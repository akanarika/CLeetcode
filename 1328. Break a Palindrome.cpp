class Solution {
public:
    string breakPalindrome(string palindrome) {
        size_t N = palindrome.length();
        
        string s = palindrome;
        for (int i = 0; i < (N / 2); i++) {
            if (palindrome[i] > 'a') {
                s[i] = 'a';
                return s;
            }
        }
        s[N - 1] = 'b';
        return N == 1 ? "" : s;
    }
};