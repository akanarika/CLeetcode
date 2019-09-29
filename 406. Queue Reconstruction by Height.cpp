class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int> a, vector<int> b) {
            return (a[0] > b[0]) || ((a[0] == b[0]) && (a[1] < b[1]));
        });
        
        vector<vector<int>> v;
        for (int i = 0; i < people.size(); i++) {
            v.insert(v.begin() + people[i][1], people[i]);
        }
        
        return v;
    }
};