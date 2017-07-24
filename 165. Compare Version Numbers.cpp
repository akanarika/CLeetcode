class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size();
        int n2 = version2.size();
        int curr_num1 = 0;
        int curr_num2 = 0;
        int i = 0;
        int j = 0;
        while (i < n1 || j < n2) {
            while (i < n1 && version1[i] != '.') {
                curr_num1 = curr_num1 * 10 + version1[i] - '0';
                i++;
            }
            while (j < n2 && version2[j] != '.') {
                curr_num2 = curr_num2 * 10 + version2[j] - '0';
                j++;
            }
            
            if (curr_num1 > curr_num2) return 1;
            if (curr_num1 < curr_num2) return -1;
            
            curr_num1 = 0;
            curr_num2 = 0;
            
            i++;
            j++;
        }
        
        return 0;
    }
};