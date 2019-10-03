class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (countIslands(grid, i, j)) count++;
            }
        }
        return count;
    }

    int countIslands(vector<vector<char>>& grid, int i, int j) {
        if ((i < 0) || (i >= grid.size()) || (j < 0) || (j >= grid[0].size())) return 0;

        if (grid[i][j] == '1') {
            grid[i][j] = 0;
            countIslands(grid, i - 1, j);
            countIslands(grid, i + 1, j);
            countIslands(grid, i, j - 1);
            countIslands(grid, i, j + 1);
            return 1;
        }

        return 0;
    }
};
