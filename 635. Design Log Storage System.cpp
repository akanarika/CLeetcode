class LogSystem {
    map<string, int> m;
public:
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        m[timestamp] = id;
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        if (gra == "Year") {
            s = s.substr(0, 5) + "00:00:00:00:00";
            e = e.substr(0, 5) + "12:31:23:59:59";
        } else if (gra == "Month") {
            s = s.substr(0, 8) + "00:00:00:00";
            e = e.substr(0, 8) + "31:23:59:59";
        } else if (gra == "Day") {
            s = s.substr(0, 11) + "00:00:00";
            e = e.substr(0, 11) + "23:59:59";
        } else if (gra == "Hour") {
            s = s.substr(0, 14) + "00:00";
            e = e.substr(0, 14) + "59:59";
        } else if (gra == "Minute") {
            s = s.substr(0, 17) + "00";
            e = e.substr(0, 17) + "59";
        }

        auto low = m.lower_bound(s);
        auto up = m.upper_bound(e);
        vector<int> res;
        while (low != up) {
            res.push_back(low->second);
            low++;
        }
        return res;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(s,e,gra);
 */
