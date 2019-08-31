class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for (auto& c : paragraph) {
            if (c != ' ' && c != '!' && c != '?' && c != '\'' && c != ',' && 
                    c != ';' && c != '.') {
                if (c >= 'A' && c <= 'Z') {
                    c += 'a' - 'A';
                }
            } else {
                c = ' ';
            }
        }

        unordered_map<string, int> count;
        size_t pos = 0;
        size_t next = 0;
        while (pos < paragraph.size() && pos != string::npos) {
            next = paragraph.find(' ', pos);
            if (!paragraph.substr(pos, next - pos).empty()) count[paragraph.substr(pos, next - pos)]++;
            pos = (next == string::npos) ? string::npos : (next + 1);
        }

        for (auto b : banned) {
            count[b] = -1;
        }

        int maxCount = 0;
        string res = "";
        for (const auto& pair : count) {
            if (pair.second > maxCount) {
                res = pair.first;
                maxCount = pair.second;
            }
        }

        return res;
    }
};
