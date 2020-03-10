/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution {
private:
    unordered_map<string, string> parents;
    unordered_map<string, unordered_map<string, double>> div;
    string find(string a) {
        if (!parents.count(a)) return "";
        while (parents[a] != parents[parents[a]]) {
            div[parents[parents[a]]][a] = div[parents[parents[a]]][parents[a]] * div[parents[a]][a];
            parents[a] = parents[parents[a]];
            a = parents[a];
        }
        return parents[a];
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            auto eq = equations[i];
            string a = eq[0];
            string b = eq[1];
            double m = values[i];
            if (!parents.count(a)) {
                parents[a] = a;
                div[a][a] = 1.0;
            }
            if (!parents.count(b)) {
                parents[b] = b;
                div[b][b] = 1.0;
            }
            string pa = find(a);
            string pb = find(b);
            parents[pb] = pa;
            double ka = div[pa][a];
            double kb = div[pb][b];
            div[pa][pb] = m * ka / kb;
                div[pb][pa] = 1.0 / div[pa][pb];
        }

        vector<double> res;
        for (const auto& q : queries) {
            string a = q[0];
            string b = q[1];
            string pa = find(a);
            string pb = find(b);
            if (!pa.empty() && !pb.empty() && pa == pb) {
                res.push_back(div[pb][b] / div[pa][a]);
            } else {
                res.push_back(-1.0);
            }
        }
        return res;
    }
};
// @lc code=end

/**
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, pair<string, double>> eqs;
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            if (!eqs.count(a) && !eqs.count(b)) {
                eqs[a] = make_pair(a, 1.0);
                eqs[b] = make_pair(a, val);
            } else if (!eqs.count(a)) {
                eqs[a] = make_pair(eqs[b].first, eqs[b].second * (1 / val));
            } else if (!eqs.count(b)) {
                eqs[b] = make_pair(eqs[a].first, eqs[a].second * val);
            } else {
                pair<string, double> ka = eqs[a];
                pair<string, double>& kb = eqs[b];
                kb.first = ka.first;
                kb.second *= val * ka.second;
            }
        }
        
        vector<double> res;
        for (int i = 0; i < queries.size(); i++) {
            string a = queries[i][0];
            string b = queries[i][1];
            if (a == b && eqs.count(a)) {
                res.push_back(1.0);
                continue;
            }
            if (eqs.count(a) && eqs.count(b)) {
                double av = 1.0;
                double bv = 1.0;
                string ap = a;
                while (eqs[ap].first != ap) {
                    av *= eqs[ap].second;
                    ap = eqs[ap].first;
                }
                string bp = b;
                while (eqs[bp].first != bp) {
                    bv *= eqs[bp].second;
                    bp = eqs[bp].first;
                }
                if (ap == bp) {
                    res.push_back(bv / av);
                } else {
                    res.push_back(-1.0);
                }
            } else {
                res.push_back(-1.0);
            }
        }
        
        return res;
    }
};
**/
