class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        sort(A.begin(), A.end(), [](int a, int b) { return (a % 2 == 0) && (b % 2 == 1);});

        int odd = 1;
        int even = A.size() - 1;
        if (even % 2 == 1) even--;

        while (even > odd) {
            int tmp = A[even];
            A[even] = A[odd];
            A[odd] = tmp;
            even -= 2;
            odd += 2;
        }

        return A;
    }
};
