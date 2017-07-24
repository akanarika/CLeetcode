class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> children;
        unordered_map<int, int> degree;
        int max_num = 0;
        for (int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i].first;
            int pre = prerequisites[i].second;
            max_num = max(max_num, max(course, pre));

            children[pre].insert(course);
        
            degree[course]++;
                      
            if (degree.find(pre) == degree.end()) {
                degree[pre] = 0;
            }
        }
        
        if (degree.size() < numCourses) {
            int d_size = degree.size();
            for (int i = 0; i < numCourses - d_size; i++) {
                degree[++max_num] = 0;
            }
        }
        
        int num = 0;
        while (num < numCourses) {
            int course = -1;
            for (auto it = degree.begin(); it != degree.end(); it++) {
                if (it->second == 0) {
                    num++;
                    course = it->first;
                    unordered_set<int> s = children[course];
                    for (auto s_it = s.begin(); s_it != s.end(); s_it++) {
                        degree[*s_it]--;
                    }
                    it->second = -1;
                    break;
                }
            }
            if (course == -1) return false;
        }
        
        return true;
        
    }
};