class Solution {
public:
    string toLowerCase(string str) {
        for (size_t i = 0; i < str.length(); i++) {
            if (((int)str[i] >= 65) && ((int)str[i] <= 91)) {
                str[i] = (char)(str[i] + 32);
            }
        }
        return str;
    }
};
