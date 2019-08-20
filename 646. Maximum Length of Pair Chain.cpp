class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.empty()) return 0;

        sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b) {
                return ((a[0] < b[0]) || ((a[0] == b[0]) && (a[1] < b[1])));
                });

        map<int, int> m;
        map<int, vector<vector<int>>> pair_map;
        
        for (auto pair : pairs) {
            pair_map[pair[0]].push_back(pair);
        }


        int res = 0;
        for (auto it = pair_map.rbegin(); it != pair_map.rend(); it++) {
            int maxCount = 1;
            for (auto anyPair : it->second) {
                int count = 1;
                bool found = false;
                for (auto otherPair : m) {
                    if (otherPair.first > anyPair[1]) {
                        count = max(count, otherPair.second);
                        maxCount = max(1 + count, maxCount);
                        found = true;
                    }
                }
                if (!found && m.find(anyPair[0]) == m.end()) m[anyPair[0]] = 1;
                else m[anyPair[0]] = maxCount;
                res = max(res, maxCount);
            }
        }
        return res;
    }
};
