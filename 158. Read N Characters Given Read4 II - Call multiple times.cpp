// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    char prevbuf[4];
    int previ = 0;
    int prevc = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int cnt = 0;
        while (cnt < n) {
            if (previ == prevc) {
                prevc = read4(prevbuf);
                previ = 0;
                if (!prevc) return cnt;
            }
            while (previ < prevc && cnt < n) buf[cnt++] = prevbuf[previ++];
        }
        return cnt;
    }
};

/**
int read4(char *buf);

class Solution {
    char prevbuf[4];
    int prevI = 0;
    int prevCount = 0;

public:
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
**/
