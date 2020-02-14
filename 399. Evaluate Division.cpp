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