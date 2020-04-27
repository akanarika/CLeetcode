class Solution {
private:
    string boardToString(vector<vector<int>>& board) {
        return to_string(board[0][0]) + to_string(board[0][1]) + to_string(board[0][2])
            + to_string(board[1][0]) + to_string(board[1][1]) + to_string(board[1][2]);
    }
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string s = "123450";
        unordered_set<string> seen;
        seen.insert(boardToString(board));
        queue<string> q;
        q.push(boardToString(board));
        vector<vector<int>> dirs = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        int step = 0;
        while(!q.empty()) {
            int n = q.size();
            while (n-- > 0) {
                auto b = q.front();
                q.pop();
                if (b == s) return step;
                int zp = 0;
                for (int p = 0; p < 6; p++) {
                    if (b[p] == '0') {
                        zp = p;
                        break;
                    }
                }
                for (auto dir : dirs[zp]) {
                    string nb = b;
                    swap(nb[dir], nb[zp]);
                    if (!seen.count(nb)) {
                        q.push(nb);
                        seen.insert(nb);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
