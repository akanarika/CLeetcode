class Solution {
public:
    int rotatedDigits(int N) {
        int num = 0;
        while (N > 0) {
            int n = N;
            bool good = false;
            while (n > 0) {
                int b = n % 10;
                if (b == 3 || b == 4 || b == 7) {
                    good = false;
                    break;
                } else if (b == 2 || b == 5 || b == 6 || b == 9) {
                    good = true;
                } 
                n /= 10;
            }
            if (good) num++;
            N--;
        }
        return num;
    }
};