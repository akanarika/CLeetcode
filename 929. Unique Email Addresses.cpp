class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, bool> map;
        for (string &email : emails) {
            bool local = true;
            bool ignore = false;
            string currentEmail = "";
            for (size_t i = 0; i < email.length(); i++) {
                if (local) {
                    if (email[i] == '@'){
                        local = false;
                        currentEmail.append("@");
                    } else if (email[i] == '.') {
                        continue;
                    } else if (email[i] == '+') {
                        ignore = true;
                        continue;
                    } else {
                        if (ignore) {
                            continue;
                        } else {
                            currentEmail += email[i];
                        }
                    }
                } else {
                    currentEmail += email[i];
                }
            }
            map[currentEmail] = true;
        }
        return map.size();
    }
};
