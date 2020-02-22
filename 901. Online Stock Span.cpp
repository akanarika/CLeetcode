/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
class StockSpanner {
private:
    vector<pair<int, int>> count;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        auto it = count.rbegin();
        int cnt = 1;
        while (it != count.rend() && it->first <= price) {
            cnt += it->second;
            it += it->second;
        }
        count.push_back(make_pair(price, cnt));
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
