class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty()) return "";
        if (num1 == "0" || num2 == "0") return "0";
        
        int n1 = num1.length();
        int n2 = num2.length();
        if (n1 < n2) {
            swap(num1, num2);
            swap(n1, n2);
        }
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int carry = 0;
        int n = 0;
        string s = "";
        while (n < n1 + n2 - 1) {
            int currSum = carry;
            for (int i = 0; i < n1; i++) {
                int j = n - i;
                if (j < 0) break;
                if (j >= n2) continue;
                int x = num1[i] - '0';
                int y = num2[j] - '0';
                currSum += x * y;
            }
            carry = currSum / 10;
            s.push_back('0' + currSum % 10);
            n++;
        }
        if (carry > 0) s.push_back('0' + carry);
        reverse(s.begin(), s.end());   
        return s;
    }
};