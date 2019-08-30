class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0;
        while (i < name.length()) {
            if (name[i] == typed[j]) {
                i++;
                j++;
            } else if (typed[j] == name[i - 1]){
                j++;
            } else
                return false;
        }
        
        return true;
    }
};
