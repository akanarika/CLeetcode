// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int totalCount = 0;
        while (totalCount < n) {
            int count = read4(buf + totalCount);
            if (count == 0) break;
            totalCount += min(count, n - totalCount);
        }

        return totalCount;
    }
};
