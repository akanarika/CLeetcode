class Solution {
public:
    string findContestMatch(int n) {
        if (n == 1) return "1";

        vector<int> v(n, 0);
        v[0] = 1;
        int inter = n / 2;
        int sum = 2;
        while (inter > 0) {
            for (int i = n - 1; i >= 0; i--) {
                if (v[i] != 0) {
                    v[i + inter] = sum + 1 - v[i];
                }
            }
            inter /= 2;
            sum *= 2;
        }

        return printVector(v, 0, n - 1);
    }

    string printVector(vector<int>& v, int s, int e) {
        if (s == e - 1) {
            return '(' + to_string(v[s]) + "," + to_string(v[e]) + ")";
        }

        return '(' + printVector(v, s, s + (e - s) / 2) + "," + printVector(v, s + 1 + (e - s) / 2, e) + ')';
    }
};
