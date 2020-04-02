class RandomizedSet {
public:
    unordered_map<int, int> index;
    vector<int> nums;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (index.count(val)) return false;
        nums.push_back(val);
        index[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!index.count(val)) return false;
        int idx = index[val];
        nums[idx] = nums[nums.size() - 1];
        index[nums[idx]] = idx;
        nums.pop_back();
        index.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % nums.size();
        return nums[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
 