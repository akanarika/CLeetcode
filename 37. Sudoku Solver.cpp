/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        rows = vector<vector<int>>(9, vector<int>(10, 0));
        cols = vector<vector<int>>(9, vector<int>(10, 0));
        blks = vector<vector<int>>(9, vector<int>(10, 0));

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                int b = (r / 3) * 3 + c / 3;
                if (board[r][c] != '.') {
                    int num = board[r][c] - '0';
                    rows[r][num] = 1;
                    cols[c][num] = 1;
                    blks[b][num] = 1;
                }
            }
        }
        solve(0, board);
    }

private:
    vector<vector<int>> rows;
    vector<vector<int>> cols;
    vector<vector<int>> blks;
    bool solve(int i, vector<vector<char>>& board) {
        int r = i / 9;
        int c = i % 9;
        int b = (r / 3) * 3 + c / 3;
        if (board[r][c] != '.') {
            if (i == 80) return true;
            return solve(i + 1, board);
        }

        for (int num = 1; num <= 9; num++) {
            if ((!rows[r][num]) && (!cols[c][num]) && (!blks[b][num])) {
                board[r][c] = (char)('0' + num);
                rows[r][num] = 1;
                cols[c][num] = 1;
                blks[b][num] = 1;
                if (i == 80 || solve(i + 1, board)) return true;
                board[r][c] = '.';
                rows[r][num] = 0;
                cols[c][num] = 0;
                blks[b][num] = 0;
            }
        }
        return false;
    }

};
    // @lc code=end
