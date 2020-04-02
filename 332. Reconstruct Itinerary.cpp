class Solution {
private:
    unordered_map<string, multiset<string>> fromto;
    vector<string> res;
    void visit(string from) {
        while (!fromto[from].empty()) {
            string curr = *fromto[from].begin();
            fromto[from].erase(fromto[from].begin());
            visit(curr);
        }
        res.push_back(from);
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (const auto& t : tickets) {
            string from = t[0];
            string to = t[1];
            fromto[from].insert(to);
        }
        
        visit("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};
