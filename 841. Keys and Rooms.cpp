class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visit(rooms, 0);
        return res == rooms.size();
    }
    
private:
    unordered_set<int> visited;
    int res = 0;
    void visit(vector<vector<int>>& rooms, int i) {
        vector<int> keys = rooms[i];
        visited.insert(i);
        res++;
        for (int key : keys) {
            if (visited.find(key) == visited.end()) visit(rooms, key);
        }
    }
};