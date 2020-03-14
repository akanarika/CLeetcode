/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
private:
    void fill(vector<vector<char>>& board, int r, int c, int h, int w) {
        if (r < 0 || r >= h || c < 0 || c >= w || board[r][c] != 'O') return;
        board[r][c] = 'Y';
        fill(board, r - 1, c, h, w);
        fill(board, r + 1, c, h, w);
        fill(board, r, c - 1, h, w);
        fill(board, r, c + 1, h, w);
    }

public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int h = board.size();
        int w = board[0].size();
        for (int c = 0; c < w; c++) {
            if (board[0][c] == 'O') fill(board, 0, c, h, w);
            if (board[h - 1][c] == 'O') fill(board, h - 1, c, h, w);
        }
        for (int r = 0; r < h; r++) {
            if (board[r][0] == 'O') fill(board, r, 0, h, w);
            if (board[r][w - 1] == 'O') fill(board, r, w - 1, h, w);
        }

        for (auto& row : board) {
            for (auto& b : row) {
                if (b == 'O') b = 'X';
                else if (b == 'Y') b = 'O';
            }
        }
    }
};
// @lc code=end
