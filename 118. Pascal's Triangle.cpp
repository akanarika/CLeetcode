class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (!numRows) return {};
        
        vector<vector<int>> res = {{1}};
        for (int i = 1; i < numRows; i++) {
            vector<int> row;
            for (int c = 0; c <= i; c++) {
                row.push_back((c == 0 ? 0 : res[i - 1][c - 1]) + (c == i? 0 : res[i - 1][c]));
            }
            res.push_back(row);
        }
        return res;
    }
};

/**
 class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0) return res;
        
        res.push_back(vector<int>(1, 1));
       
        for (int i = 1; i < numRows; i++) {
            vector<int> curr;
            for (int j = 0; j <= res[i-1].size(); j++) {
                if (j == 0 || j == res[i-1].size()) {
                    curr.push_back(1);
                } else {
                    curr.push_back(res[i-1][j-1] + res[i-1][j]);
                }
            }
            res.push_back(curr);
        }
        
        return res;
    }
};
**/
