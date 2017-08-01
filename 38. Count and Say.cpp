class Solution {
public:
    string countAndSay(int n) {
        int i = 2;
        string curr_num = "11";
        string new_num = "";
        while (i < n) {
            string curr_bit = to_string(curr_num[0] - '0');
            int len = curr_num.size();
            new_num = "";
            int count = 1;
            int j = 0;
            while (j < len - 1) {
                if (curr_num[j] == curr_num[j+1]) {
                    count++;
                } else {
                    new_num += to_string(count) + curr_bit;
                    curr_bit = to_string(curr_num[j+1] - '0');
                    count = 1;
                }
                if (j + 1 == len - 1) {
                    new_num += to_string(count) + curr_bit;
                }
                j++;
            }
            curr_num = new_num;
            i++;
        }
        return n <= 1 ? "1" : curr_num;
    }
};