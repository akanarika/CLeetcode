class Solution {
private:
    int h, w;
    void color(int i, int j, vector<vector<int>>& A) {
        if (i < 0 || i >= h || j < 0 || j >= w || A[i][j] != 1) return;
        A[i][j] = 2;
        color(i - 1, j, A);
        color(i + 1, j, A);
        color(i, j - 1, A);
        color(i, j + 1, A);
    }
    
    bool expand(int i, int j, vector<vector<int>>& A, int step) {
        if (i < 0 || i >= h || j < 0 || j >= w) return false;
        if (!A[i][j]) A[i][j] = step + 1;
        return A[i][j] == 1;
    }
    
public:
    int shortestBridge(vector<vector<int>>& A) {
        h = A.size();
        w = A[0].size();
        
        for (int i = 0; i < h * w; i++) {
            if (A[i / w][i % w]) {
                color(i / w, i % w, A);
                break;
            }
        }
        
        int step = 1;
        while (++step) 
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (A[i][j] == step) {
                    if (expand(i - 1, j, A, step) || expand(i + 1, j, A, step) || expand(i, j - 1, A, step) || expand(i, j + 1, A, step)) {
                        return step - 2;
                    }
                }
            }
        }
        return 0;
    }
};
