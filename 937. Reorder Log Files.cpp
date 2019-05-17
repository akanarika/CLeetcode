class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<size_t> num;
        unordered_map<string, int> map;
        vector<string> alp;
        for (size_t i = 0; i < logs.size(); i++) {
            size_t firstSpacePos = logs[i].find(" ");
            if (logs[i][firstSpacePos + 1] >= 97) {
                map[logs[i].substr(firstSpacePos + 1) + logs[i].substr(0, firstSpacePos)] = i;
                alp.push_back(logs[i].substr(firstSpacePos + 1) + logs[i].substr(0, firstSpacePos));
            } else {
                num.push_back(i);
            }
        }
        sort(alp.begin(), alp.end());
        vector<string> res;
        for (auto a : alp) {
            res.push_back(logs[map[a]]);
        }
        for (auto n : num) {
            res.push_back(logs[n]);
        }
        return res;
    }
};
