class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream in1(version1);
        istringstream in2(version2);

        int num1, num2;
        while ((in1.peek() != EOF) || (in2.peek() != EOF)) {
            if (!(in1 >> num1)) num1 = 0;
            else in1.get();
            if (!(in2 >> num2)) num2 = 0;
            else in2.get();
            if (num1 > num2) return 1;
            else if (num2 > num1) return -1;
            else continue;
        }

        return 0;
    }
};
