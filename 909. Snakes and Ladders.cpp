class Solution {
    int N;
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) return 0;
        
        N = board.size();
        
        vector<vector<int>> steps(N, vector<int>(N, INT_MAX));
        steps[N - 1][0] = 0;
        vector<int> level = {1};
        
        while (!level.empty()) {
            vector<int> newLevel;
            for (auto start : level) {
                int sr = idx(start)[0];
                int sc = idx(start)[1];
                int step = steps[sr][sc];
                for (int i = 1; i <= 6 && start + i <= N * N; i++) {
                    int row = idx(start + i)[0];
                    int col = idx(start + i)[1];
                    
                    int c = board[row][col];
                    if (c != -1 && c <= N * N) {
                        int nr = idx(c)[0];
                        int nc = idx(c)[1];
                        if (steps[nr][nc] > step + 1) {
                            steps[nr][nc] = step + 1;
                            newLevel.push_back(num(nr, nc));
                        }
                    } else {
                        if (steps[row][col] > step + 1) {
                            steps[row][col] = step + 1;
                            newLevel.push_back(start + i);
                        }
                    }
                }
            }
            level = newLevel;
        }
        int res = steps[idx(N * N)[0]][idx(N * N)[1]];
        return res == INT_MAX ? -1 : res;
    }
    
    vector<int> idx(int num) {
        num--;
        int row = N - 1 - num / N;
        int col = 0;
        if (N % 2) {
            col = (row % 2 ? (N - 1 - num % N) : num % N);
        } else {
            col = (row % 2 ? num % N : (N - 1 - num % N));
        }
        return {row, col};
    }
    
    int num(int row, int col) {
        int off = 0;
        if (N % 2) {
            off = (row % 2) ? (N - col - 1) : (col);
        } else {
            off = (row % 2) ? col : (N - col - 1);
        }
        return 1 + (N - row - 1) * N + off;
    }
};
