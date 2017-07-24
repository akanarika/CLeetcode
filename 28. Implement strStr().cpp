class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        int tbl[needle.size()];
        buildTbl(needle, tbl);
        int i = 0;
        int j = 0;
        while (i < haystack.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if (j == needle.size()) {
                return i - j;
            } else if (i < haystack.size() && haystack[i] != needle[j]) {
                if (j != 0) j = tbl[j-1];
                else i++;
            }
        }
        return -1;
    }
private:
    void buildTbl(string needle, int* tbl) {
        int len = 0;
        int i = 1;
        tbl[0] = 0;
        while (i < needle.size()) {
            if (needle[i] == needle[len]) {
                len++;
                tbl[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = tbl[len-1];
                } else {
                    tbl[i] = 0;
                    i++;
                }
            }
        }
    }
};