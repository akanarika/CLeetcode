class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        
        int bound = matrix[0].size();
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < bound; j++) {
                if (matrix[i][j] == target) return true;
                if (matrix[i][j] > target) bound = j;
            }
        }
        
        return false;
    }
};