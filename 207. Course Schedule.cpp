/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> degree;
        for (int i = 0; i < prerequisites.size(); i++) {
            vector<int> p = prerequisites[i];
            for (int j = 0; j < p.size(); j++) {
                if (j > 0) degree[p[j]]++;
            }
        }
        vector<int> idx(prerequisites.size(), 0);
        while (true) {
            bool exist = false;
            bool empty = true;
            for (int i = 0; i < prerequisites.size(); i++) {
                vector<int> p = prerequisites[i];
                if (idx[i] >= p.size()) continue;
                empty = false;
                if (degree[p[idx[i]]] == 0) {
                    exist = true;
                    idx[i]++;
                    numCourses--;
                    if (idx[i] < p.size()) {
                        degree[p[idx[i]]]--;
                    }
                }
            }
            if (empty) return true;
            if (!empty && !exist) return false;
        }
        return true;
    }
};
// @lc code=end

/**
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
**/
