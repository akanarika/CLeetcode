class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<pair<int, int>> q;
        for (int i = 0; i < nums.size(); i++) {
            while (!q.empty() && (i - q.front().second >= k)) {
                q.pop_front();
            }
            while (!q.empty() && (q.back().first < nums[i])) {
                q.pop_back();
            }
            q.emplace_back(nums[i], i);
            if (i >= k - 1) res.push_back(q.front().first);
        }
        return res;
    }
};

/**
class Solution {
private:
    class Q {
        deque<int> q;
    public:
        void push(int num) {
            while (!q.empty() && q.back() < num) {
                q.pop_back();
            }
            q.push_back(num);
        }
        void pop() {
            q.pop_front();
        }
        int max() {
            return q.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Q myq = Q();
        for (int i = 0; i < k - 1; i++) myq.push(nums[i]);
        vector<int> res;
        for (int i = k - 1; i < nums.size(); i++) {
            myq.push(nums[i]);
            res.push_back(myq.max());
            if (nums[i - k + 1] == myq.max()) myq.pop();
        }
        return res;
    }
};
 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return {};
        deque<int> q;
        vector<int> res;
        int i = 0, j = 0;
        while (j - i < k) {
            while (!q.empty() && (q.back() < nums[j])) q.pop_back();
            q.push_back(nums[j++]);
        }
        res.push_back(q.front());
        while (j < nums.size()) {
            if (q.front() == nums[i++]) q.pop_front();
            while (!q.empty() && (q.back() < nums[j])) q.pop_back();
            q.push_back(nums[j++]);
            res.push_back(q.front());
        }
        return res;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return {};
        multiset<int> s;
        for (int i = 0; i < k; i++) s.insert(nums[i]);

        vector<int> res;
        for (int i = 0; i < nums.size() - k; i++) {
            res.push_back(*s.rbegin());
            
            s.insert(nums[i + k]);
            s.erase(s.lower_bound(nums[i]));
        }
        res.push_back(*s.rbegin());
        return res;
    }
};
**/

