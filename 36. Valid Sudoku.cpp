class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int blk[9][9] = {0};
        
        for (int i = 0; i < board.size(); i++) {
            vector<int> exist(9, 0);
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    if (row[i][board[i][j]-'0'-1] 
                        | col[j][board[i][j]-'0'-1]
                        | blk[3*(i/3)+j/3][board[i][j]-'0'-1]) return false;
                    else {
                        row[i][board[i][j]-'0'-1] =
                        col[j][board[i][j]-'0'-1] =
                        blk[3*(i/3)+j/3][board[i][j]-'0'-1] = 1;
                    }
                }
            }
        }
        
        return true;
    }
};

/*
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            vector<int> exist(9, 0);
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    if (exist[board[i][j]-'0'-1] < 1) {
                        exist[board[i][j]-'0'-1] = 1;
                    } else {
                        return false;
                    }
                }
            }
        }
        
        for (int i = 0; i < board[0].size(); i++) {
            vector<int> exist(9, 0);
            for (int j = 0; j < board.size(); j++) {
                if (board[j][i] != '.') {
                    if (exist[board[j][i]-'0'-1] < 1) {
                        exist[board[j][i]-'0'-1] = 1;
                    } else {
                        return false;
                    }
                }
            }
        }
        
        for (int i = 0; i < 9; i++) {
            vector<int> exist(9, 0);
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    int m = j + (i/3)*3;
                    int n = k + (i%3)*3;
                    if (board[m][n] != '.') {
                        if (exist[board[m][n]-'0'-1] < 1) {
                            exist[board[m][n]-'0'-1] = 1;
                        } else {
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};
*/