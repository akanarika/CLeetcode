class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, vector<int>> m;
        for (auto t : time) {
            m[t % 60].push_back(t);
        }

        int size = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            if ((it->first == 0) || m.find(60 - it->first) != m.end()) {
                if (it->first == 30 || it->first == 0) {
                    size += it->second.size() * (it->second.size() - 1) / 2; 
                } else {
                    size += it->second.size() * m[60 - it->first].size();
                }
                m[it->first].clear();
            }
        }
        return size;
    }
};
