/*
 * @lc app=leetcode id=364 lang=cpp
 *
 * [364] Nested List Weight Sum II
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int sum = 0;
        int dep = 1;
        depth(dep, 1, nestedList);
        for (auto nl : nestedList) {
            sum += depthSum(dep, nl);
        }
        return sum;
    }
    
    void depth(int& maxDep, int dep, vector<NestedInteger>& nestedList) {
        for (auto nl : nestedList) {
            if (!nl.isInteger()) depth(maxDep, dep + 1, nl.getList());
            else maxDep = max(maxDep, dep);
        }
    }

    int depthSum(int depth, NestedInteger nl) {
        if (nl.isInteger()) return depth * nl.getInteger();

        auto nestedList = nl.getList();
        int sum = 0;
        for (auto nnl : nestedList) {
            sum += depthSum(depth - 1, nnl);
        }
        return sum;
    }
};
// @lc code=end
