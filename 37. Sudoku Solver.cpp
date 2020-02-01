/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        /**
        unordered_set<int> defaultSet = {1,2,3,4,5,6,7,8,9};
        vector<vector<unordered_set<int>>> possibleNumbers(9, vector<unordered_set<int>>(9, defaultSet));
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] != '.') {
                    int num = board[row][col] - '0';
                    for (int c = 0; c < 9; c++) {
                        if (board[row][c] == '.') possibleNumbers[row][c].erase(num);
                    }
                    for (int r = 0; r < 9; r++) {
                        if (board[r][col] == '.') possibleNumbers[r][col].erase(num);
                    }
                    int blockR = row / 3;
                    int blockC = col / 3;
                    for (int br = 0; br < 3; br++) {
                        for (int bc = 0; bc < 3; bc++) {
                            if (board[blockR + br][blockC + bc] == '.') possibleNumbers[blockR + br][blockC + bc].erase(num);
                        }
                    }
                    possibleNumbers[row][col].clear();
                    possibleNumbers[row][col].insert(num);
                }
            }
        }
        solve(0, 0, possibleNumbers);
        **/
        vector<vector<unordered_set<int>>> poNum;
        solve(0, 1, poNum, board);
    }

    bool solve(int i, int num, vector<vector<unordered_set<int>>>& poNum, vector<vector<char>>& board) {
        int row = i / 9;
        int col = i % 9;
        if (board[row][col] != '.') {
            if (i == 80) return true;
            return solve(i + 1, 1, poNum, board);
        } else {
            board[row][col] = (char)(num + '0');
            if (check(row, col, num, board)) {
                if (i == 80) return true;
                return solve(i + 1, 1, poNum, board);
            } else {
                bool can = solve(i, num + 1, poNum, board);
                if (can) return true;
                else {
                    board[row][col] = '.';
                    return solve(i, num + 1, poNum, board);
                }
            }
        }
    }

    bool check(int row, int col, int num, vector<vector<char>>& board) {
        cout << "[" << row << "," << col << "]" << ": " << num << ";";
        for (int c = 0; c < 9; c++) {
            if (c == col) continue;
            if (board[row][c] == '.') continue;
            if ((board[row][c] - '0') == num) return false;
        }

        for (int r = 0; r < 9; r++) {
            if (r == row) continue;
            if (board[r][col] == '.') continue;
            if ((board[r][col] - '0') == num) return false;
        }
        int blockR = row / 3;
        int blockC = col / 3;
        for (int br = 0; br < 3; br++) {
            for (int bc = 0; bc < 3; bc++) {
                if ((blockR + br == row) && (blockC + bc == col)) continue;
                if (board[blockR + br][blockC + bc] == '.') continue;
                if ((board[blockR + br][blockC + bc] - '0') == num) return false;
            }
        }
        return true;
    }
};
// @lc code=end
