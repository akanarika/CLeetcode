class Solution {
public:
    typedef pair<int, int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (const auto& num : nums) {
            cnt[num]++;
        }
        
        priority_queue<pi, vector<pi>, greater<pi>> q;
        for (auto pr : cnt) {
            if (q.size() < k || q.top().first < pr.second) {
                q.emplace(pr.second, pr.first);
            }
            if (q.size() > k) q.pop();
        }
        
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};

/**
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto num : nums) {
            m[num]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto p : m) {
            pq.push(make_pair(p.second, p.first));
        };

        vector<int> res;
        while (!pq.empty()) {
            if (pq.size() > m.size() - k) {
                res.push_back(pq.top().second);
            }
            pq.pop();
        }


        return res;
    }
};
**/
