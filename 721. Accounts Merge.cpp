class Solution {
private:
    unordered_map<string, string> parent;
    unordered_map<string, string> name;
    string find(string s) {
        while (parent[s] != parent[parent[s]]) {
            parent[s] = parent[parent[s]];
            s = parent[s];
        }
        return parent[s];
    }
    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (const auto& account : accounts) {
            if (account.size() <= 1) continue;
            string accname = account[0];
            string key = parent.count(account[1]) ? find(account[1]) : account[1];
            parent[account[1]] = key;
            name[account[1]] = accname;
            for (int i = 2; i < account.size(); i++) {
                if (parent.count(account[i])) {
                    string ckey = find(account[i]);
                    if (ckey != key) {
                        parent[key] = ckey;
                        key = ckey;
                    }
                } else {
                    parent[account[i]] = key;
                }
                name[account[i]] = accname;
            }
        }
        
        unordered_map<string, vector<string>> res;
        for (auto p : parent) {
            res[find(p.second)].push_back(p.first);
        }
        
        vector<vector<string>> ress;
        for (auto r : res) {
            vector<string> v = r.second;
            sort(v.begin(), v.end());
            v.insert(v.begin(), name[r.first]);
            ress.push_back(v);
        }
        return ress;
        
    }
};
