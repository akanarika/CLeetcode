typedef pair<int, int> pi;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        priority_queue<pi, vector<pi>, greater<pi>> q;
        q.push(make_pair(T[0], 0));
        for (int i = 1; i < T.size(); i++) {
            int temp = T[i];
            if (q.top().first < temp) {
                while ((!q.empty()) && (q.top().first < temp)) {
                    T[q.top().second] = i - q.top().second;
                    q.pop();    
                }
            }
            q.push(make_pair(T[i], i));
        }
        
        while (!q.empty()) {
            T[q.top().second] = 0;
            q.pop();
        }
        
        return T;
    }
};