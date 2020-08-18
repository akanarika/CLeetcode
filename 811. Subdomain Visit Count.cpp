class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        if (cpdomains.empty()) return {};
        unordered_map<string, int> cnt;
        for (auto domain : cpdomains) {
            int found = domain.find(" ");
            int number = 0;
            if (found != string::npos) {
                string numstr = domain.substr(0, found);
                number = stoi(numstr);
            }
            string curr = "";
            for (int i = domain.length() - 1; i >= found; i--) {
                if (domain[i] == '.' || i == found) {
                    cnt[curr] += number;
                }
                curr = domain[i] + curr;
            }
        }
        
        vector<string> res;
        for (auto pair : cnt) {
            res.push_back(to_string(pair.second) + " " + pair.first);
        }
        return res;
    }
};