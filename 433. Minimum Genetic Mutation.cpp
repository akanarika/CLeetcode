/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

// @lc code=start
class Solution {
private:
    bool compare(string a, string b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                if (diff > 0) return false;
                diff++;
            }
        }
        return diff == 1;
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, vector<string>> neighbors;
        bank.push_back(start);
        for (auto it = bank.begin(); it != bank.end(); it++) {
            for (auto other = it + 1; other != bank.end(); other++) {
                if (compare(*it, *other)) {
                    neighbors[*it].push_back(*other);
                    neighbors[*other].push_back(*it);
                }
            }
        }

        unordered_set<string> visited;
        unordered_map<string, int> count;
        stack<string> next;
        next.push(start);
        count[start] = 0;
        while (!next.empty()) {
            stack<string> newNext;
            while (!next.empty()) {
                string node = next.top();
                next.pop();
                visited.insert(node);
                for (auto nei : neighbors[node]) {
                    if (!visited.count(nei)) {
                        newNext.push(nei);
                        count[nei] = count[node] + 1;
                        if (nei == end) return count[nei];
                    }
                }
            }
            swap(next, newNext);
        }
        return -1;
    }
};
// @lc code=end
