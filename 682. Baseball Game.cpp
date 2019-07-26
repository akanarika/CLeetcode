class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> scores;
        for (auto op : ops) {
            if (op == "+") {
                int s1 = scores.top();
                scores.pop();
                int s2 = scores.top();
                scores.push(s1);
                scores.push(s1 + s2);
            } else if (op == "D") {
                scores.push(scores.top() * 2);
            } else if (op == "C") {
                scores.pop();
            } else {
                scores.push(stoi(op));
            }
        }

        int sum = 0;
        while (scores.size()) {
            sum += scores.top();
            scores.pop();
        }

        return sum;
    }
};
