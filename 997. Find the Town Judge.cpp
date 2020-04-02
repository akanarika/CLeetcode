class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trusting(N + 1, 0);
        vector<int> trusted(N + 1, 0);
        
        for (const auto& t : trust) {
            // a trusts b
            int a = t[0];
            int b = t[1];
            trusting[a]++;
            trusted[b]++;
        }
        
        for (int i = 1; i <= N; i++) {
            if (!trusting[i] && trusted[i] == N - 1) return i;
        }
        return -1;
    }
};

/**
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map<int, int> trusting;
        unordered_map<int, int> trusted;

        for (auto pair : trust) {
            int a = pair[0];
            int b = pair[1];
            trusting[a]++;
            trusted[b]++;
        }

        unordered_set<int> res;
        for (int i = 1; i <= N; i++) {
            if (!trusting.count(i)) {
                res.insert(i);
            }
        }

        int judge = -1;
        for (auto t : res) {
            if (trusted.count(t) && trusted[t] == N - 1 || !trusted.count(t) && N == 1) {
                if (judge != -1) return -1;
                judge = t;
            }
        }

        return judge;
    }
};
**/
