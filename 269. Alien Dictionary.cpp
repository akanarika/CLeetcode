class Solution {
private:
    class Node {
    public:
        int d;
        char c;
        unordered_set<char> children;
        Node(char _c) : d(0), c(_c) {}
    };

public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, Node*> dict;
        unordered_set<char> starts;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                if (dict.count(words[i][j])) continue;
                Node* w = new Node(words[i][j]);
                starts.insert(words[i][j]);
                dict[words[i][j]] = w;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            int j = 0;
            while (j < words[i].size() && j < words[i + 1].size() && words[i][j] == words[i + 1][j]) j++;
            if (j == words[i + 1].size() && j < words[i].size()) return "";
            if (j < words[i].size() && j < words[i + 1].size()) {
                char c1 = words[i][j];
                char c2 = words[i + 1][j];
                if (!dict[c1]->children.count(c2)) {
                    dict[c1]->children.insert(c2);
                    dict[c2]->d++;
                    starts.erase(c2);
                }
            }
        }
        
        string s = "";
        unordered_set<char> seen;
        while (!starts.empty()) {
            char c = *starts.begin();
            s += c;
            for (auto child : dict[c]->children) {
                if (dict[child]->d > 0) dict[child]->d--;
                if (!dict[child]->d) {
                    if (seen.count(child)) return "";
                    starts.insert(child);
                }
            }
            seen.insert(c);
            starts.erase(c);
        }
        if (s.length() != dict.size()) return "";
        return s;
    }
};
