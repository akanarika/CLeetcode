class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i;
        int n = 0;
        vector<int>::iterator it = nums.begin();
        while (it != nums.end()) {
            if (*it == 0) {
                n++;
                nums.erase(it);
            } else {
                it++;
            }
        }
        while (n) {
            nums.push_back(0);
            n--;
        }
    }
};