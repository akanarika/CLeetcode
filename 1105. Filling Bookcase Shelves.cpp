/*
 * @lc app=leetcode id=1105 lang=cpp
 *
 * [1105] Filling Bookcase Shelves
 */

// @lc code=start
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        if (books.empty()) return 0;
        vector<int> hi(books.size(), INT_MAX);
        hi[0] = books[0][1];
        for (int i = 0; i < books.size(); i++) {
            int h = 0;
            int w = 0;
            for (int j = i; j < books.size(); j++) {
                w += books[j][0];
                if (w <= shelf_width) {
                    h = max(h, books[j][1]);
                    hi[j] = min(hi[j], i > 0 ? hi[i - 1] + h : h);
                }
            }
        }
        return hi[books.size() - 1];
    }
};
// @lc code=end
