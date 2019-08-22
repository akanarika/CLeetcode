class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int w = 0;
        int h = board.size();
        for (int i = 0; i < h; i++) {
            w = board[i].size();
            for (int j = 0; j < w; j++) {
                // left
                if ((j - 1 >= 0) && (board[i][j - 1] % 10 == 1)) board[i][j] += 10;
                // up left
                if ((j - 1 >= 0) && (i - 1 >= 0) && (board[i - 1][j - 1] % 10 == 1)) board[i][j] += 10; 
                // up
                if ((i - 1 >= 0) && (board[i - 1][j] % 10 == 1)) board[i][j] += 10;
                // up right
                if ((i - 1 >= 0) && (j + 1 < w) && (board[i - 1][j + 1] % 10 == 1)) board[i][j] += 10;
                // right
                if ((j + 1 < w) && (board[i][j + 1] % 10 == 1)) board[i][j] += 10;
                // down right
                if ((i + 1 < h) && (j + 1 < w) && (board[i + 1][j + 1] % 10 == 1)) board[i][j] += 10;
                // down
                if ((i + 1 < h) && (board[i + 1][j] % 10 == 1)) board[i][j] += 10;
                // down left
                if ((i + 1 < h) && (j - 1 >= 0) && (board[i + 1][j - 1] % 10 == 1)) board[i][j] += 10;
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int n = board[i][j] / 10;
                if (board[i][j] % 10 == 1) {
                    if (n < 2 || n > 3) board[i][j] = 0;
                    else board[i][j] = 1;
                } else {
                    if (n == 3) board[i][j] = 1;
                    else board[i][j] = 0;
                }
            }
        }
    }
};
