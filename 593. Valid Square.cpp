class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> ps = {p1, p2, p3, p4};
        sort(ps.begin(), ps.end(), [](vector<int> a, vector<int> b) {
                return (a[0] < b[0]) || ((a[0] == b[0]) && (a[1] < b[1]));
                });

        if (ps[0][0] == ps[1][0]) {
            vector<int> a = sub(ps[1], ps[0]);
            vector<int> b = sub(ps[2], ps[0]);
            vector<int> c = sub(ps[3], ps[2]);
            return isValid(a, b, c);
        } else {
            vector<int> a = sub(ps[1], ps[0]);
            vector<int> b = sub(ps[2], ps[0]);
            vector<int> c = sub(ps[3], ps[2]);
            return isValid(a, b, c);
        }
    }

    int len2(vector<int> v) {
        return v[0] * v[0] + v[1] * v[1];
    }

    vector<int> sub(vector<int> v1, vector<int> v2) {
        return {v1[0] - v2[0], v1[1] - v2[1]};
    }

    int pro(vector<int> v1, vector<int> v2) {
        return v1[0] * v2[0] + v1[1] * v2[1];
    }

    bool isValid(vector<int> a, vector<int> b, vector<int> c) {
        return (len2(a) == len2(b)) && (len2(b) == len2(c)) && !pro(a, b) && !pro(b, c) && len2(a);
    }
};
