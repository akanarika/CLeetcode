class Solution {
public:
    string toGoatLatin(string S) {
        if (S.empty()) {
            return S;
        }
        
        int wordBegin = 0;
        int wordEnd = 0;
        string suffix ("ma");
        string newS;
        for (int i = 0; i <= S.length(); i++) {
            if (i == S.length() || S[i] == ' ') {
                wordEnd = i - 1;
                suffix += "a";
                if (S[wordBegin] == 'a' || S[wordBegin] == 'e' || S[wordBegin] == 'i' || S[wordBegin] == 'o' || S[wordBegin] == 'u' || S[wordBegin] == 'A' || S[wordBegin] == 'E' || S[wordBegin] == 'I' || S[wordBegin] == 'O' || S[wordBegin] == 'U') {
                    newS += S.substr(wordBegin, wordEnd - wordBegin + 1) + suffix + " ";
                } else {
                    newS += S.substr(wordBegin + 1, wordEnd - wordBegin) + S[wordBegin] + suffix  + " ";
                }
                wordBegin = i + 1;
                wordEnd = i + 1;
            } 
        }
        
        return newS.substr(0, newS.length() - 1);
    }
};
