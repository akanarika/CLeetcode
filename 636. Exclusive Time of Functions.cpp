class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<pair<int, int>> stk;
        for (const auto& log : logs) {
            istringstream in(log); int id; in >> id; in.get();
            if (in.peek() == 's') {
                in.ignore(6, ' '); int time; in >> time;
                stk.push(make_pair(id, time));
            } else {
                in.ignore(4, ' '); int time; in >> time;
                int duration = time - stk.top().second + 1;
                res[id] += duration;
                stk.pop();
                if (!stk.empty()) res[stk.top().first] -= duration;
            }
        }
        return res;
    }
};
