/*
 * @lc app=leetcode id=158 lang=cpp
 *
 * [158] Read N Characters Given Read4 II - Call multiple times
 */

// @lc code=start
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
    char prevbuf[4];
    int prevI = 0;
    int prevCount = 0;

public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int totalCount = 0;

        while (totalCount < n) {
            if (prevI < prevCount) {
                buf[totalCount++] = prevbuf[prevI++];
            } else {
                prevCount = read4(prevbuf);
                prevI = 0;
                if (prevCount == 0) break;
            }
        }

        return totalCount;
    }
};
// @lc code=end
