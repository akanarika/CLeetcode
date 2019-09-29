class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> net;
        for (int i = 0; i < gas.size(); i++) {
            net.push_back(gas[i] - cost[i]);
        }
        
        for (int i = 0; i < net.size(); i++) {
            int sum = 0;
            if (net[i] >= 0) {
                bool can = true;
                for (int k = 0; k < net.size(); k++) {
                    sum += net[(i + k) % net.size()];
                    if (sum < 0) {
                        can = false;
                        break;
                    }
                }
                if (can) return i;
            }
        }
        return -1;
    }
};