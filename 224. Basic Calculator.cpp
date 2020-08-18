class Solution {
public:
    int calculate(string s) {
        istringstream is(s);
        stack<pair<int, string>> stk;
        stk.emplace(0, "+");
        
        while (!is.eof()) {
            if (isdigit(is.peek())) {
                int num = 0;
                is >> num;
                stk.top().first += (stk.top().second == "+" ? num : -num);
            } else if (is.peek() == '(') {
                is.get();
                stk.push(make_pair(0, "+"));
            } else if (is.peek() == ')') {
                is.get();
                int num = stk.top().first;
                stk.pop();
                stk.top().first += (stk.top().second == "+" ? num : -num);
            } else if (is.peek() == '+' || is.peek() == '-') {
                stk.top().second = is.get();
            } else {
                is.get();
            }
        }
        
        return stk.top().first;
    }
};