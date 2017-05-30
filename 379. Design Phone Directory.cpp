class PhoneDirectory {
public:
    vector<int> recycled;
    unordered_map <int, int> dic;
    int max;
    int max_num;
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        max = -1;
        max_num = maxNumbers;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (recycled.size()) {
            int num = recycled.back();
            recycled.pop_back();
            dic[num] = 1;
            return num;
        } else {
            ++max;
            if (max >= max_num) return -1;
            dic[max] = 1;
            return max;
        }
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return dic.find(number) == dic.end();
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (dic.find(number) != dic.end()) {
            recycled.push_back(number);
            dic.erase(number);
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */