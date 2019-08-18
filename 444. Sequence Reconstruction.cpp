class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        vector<int> next;
        for (auto it = seqs.begin(); it != seqs.end(); it++) {
            auto seq = (*it);
            if (!seq.empty()) {
                if(find(next.begin(), next.end(), seq[0]) == next.end()) next.push_back(seq[0]);
            } else {
                seqs.erase(it);
                it--;
            }
        }

        for (const auto& element : org) {
            if (find(next.begin(), next.end(), element) == next.end()) {
                return false;
            } else {
                next.clear();
                for (auto it = seqs.begin(); it != seqs.end(); it++) {
                    if ((*it)[0] == element) {
                        it->erase(it->begin());
                        if (!(it->empty())) {
                            next.push_back((*it)[0]);
                        }
                    }
                    if (it->empty()) {
                        seqs.erase(it);
                        it--;
                    }
                }
            }
        }
       
        return seqs.empty();
    }
};
