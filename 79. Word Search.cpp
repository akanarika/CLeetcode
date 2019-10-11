/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;

        int h = board.size();
        int w = board[0].size();
        unordered_map<char, queue<vector<int>>> m;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                m[board[i][j]].push({i, j});
            }
        }

        while (!m[word[0]].empty()) {
            vector<vector<char>> nb = board;
            auto ij = m[word[0]].front();
            m[word[0]].pop();
            if (check(word, 0, ij[0], ij[1], h, w, nb)) return true;
        }
        return false;
    }

    bool check(string word, int p, int i, int j, int h, int w, vector<vector<char>>& board) {
        if (p == word.size()) return true;
        if ((i >= 0) && (i < h) && (j >= 0) && (j < w) && (board[i][j] == word[p])) {
            char c = board[i][j];
            board[i][j] = '-';
            if (check(word, p + 1, i - 1, j, h, w, board) ||
                    check(word, p + 1, i + 1, j, h, w, board) ||
                    check(word, p + 1, i, j - 1, h, w, board) ||
                    check(word, p + 1, i, j + 1, h, w, board)) {
                return true;
            }
            board[i][j] = c;
        }
        return false;
    }
};
// @lc code=end
