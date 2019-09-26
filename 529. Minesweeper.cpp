class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board.empty() || board[0].empty() || click.empty()) return {};
        int x = click[1];
        int y = click[0];
        if (board[y][x] == 'M') {
            board[y][x] = 'X'; 
            return board;
        }
        updateBoard(board, x, y);
        return board;
    }

    void updateBoard(vector<vector<char>>& board, int x, int y) {
        if (board[y][x] == 'E') {
            board[y][x] = 'V';
            char above = checkBoard(board, x, y - 1);
            char below = checkBoard(board, x, y + 1);
            char left = checkBoard(board, x - 1, y);
            char right = checkBoard(board, x + 1, y);
            char la = checkBoard(board, x - 1, y - 1);
            char lb = checkBoard(board, x - 1, y + 1);
            char ra = checkBoard(board, x + 1, y - 1);
            char rb = checkBoard(board, x + 1, y + 1);
            vector<char> adj = {above, below, left, right, la, lb, ra, rb};
            int ms = count(adj.begin(), adj.end(), 'M');
            if (ms > 0) board[y][x] = '0' + ms;
            else {
                board[y][x] = 'B';
                if (above != 'N') updateBoard(board, x, y - 1);
                if (below != 'N') updateBoard(board, x, y + 1);
                if (left != 'N') updateBoard(board, x - 1, y);
                if (right != 'N') updateBoard(board, x + 1, y);
                if (la != 'N') updateBoard(board, x - 1, y - 1);
                if (lb != 'N') updateBoard(board, x - 1, y + 1);
                if (ra != 'N') updateBoard(board, x + 1, y - 1);
                if (rb != 'N') updateBoard(board, x + 1, y + 1);
            }
        }
    }

    char checkBoard(vector<vector<char>> board, int x, int y) {
        if (x < 0 || x >= board[0].size() || y < 0 || y >= board.size()) return 'N';
        else return board[y][x];
    }
};
