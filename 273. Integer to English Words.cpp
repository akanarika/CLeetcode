class Solution {
private:
    string d1(int num) {
        vector<string> dict = {"", "One", "Two", "Three", "Four", "Five",
                      "Six", "Seven", "Eight", "Nine"};
        return dict[num];
    }
    
    string d2(int num) {
        if (num < 10) return d1(num);
        vector<string> dict1 = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                              "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> dict2 = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
                               "Eighty", "Ninety"};
        if (num < 20) return dict1[num - 10];
        else {
            string s1 = d1(num % 10);
            return dict2[(num / 10) - 2] + (s1.empty() ? "" : (" " + s1));
        }
    }
    
    string d3(int num) {
        if (num < 100) return d2(num);
        int h = num / 100;
        string s2 = d2(num % 100);
        return d1(h) + " Hundred" + (s2.empty() ? "" : " " + s2);
    }
    
    string d456(int num) {
        if (num < 1000) return d3(num);
        int t = num / 1000;
        string s3 = d3(num % 1000);
        return d3(t) + " Thousand" + (s3.empty() ? "" : " " + s3);
    }
    
    string d789(int num) {
        if (num < 1000000) return d456(num);
        int m = num / 1000000;
        string s4 = d456(num % 1000000);
        return d3(m) + " Million" + (s4.empty() ? "" : " " + s4);
    }
    
    string d101112(int num) {
        if (num < 1000000000) return d789(num);
        int b = num / 1000000000;
        string s7 = d789(num % 1000000000);
        return d3(b) + " Billion" + (s7.empty() ? "" : " " + s7);
    }
    
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        else if (num < 10) return d1(num);
        else if (num < 100) return d2(num);
        else if (num < 1000) return d3(num);
        else if (num < 1000000) return d456(num);
        else if (num < 1000000000) return d789(num);
        else return d101112(num);
        return "";
    }
};
