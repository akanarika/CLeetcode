class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        auto pa = parse(a);
        auto pb = parse(b);

        int na = pa.first * pb.first - pa.second * pb.second;
        int nb = pa.second * pb.first + pb.second * pa.first;
        return to_string(na) + "+" + to_string(nb) + "i";
    }

    pair<int, int> parse(string a) {
        int aa = 0;
        int bb = 0;
        auto ppos = a.find('+');
        if (ppos != string::npos) aa = stoi(a.substr(0, ppos));
        auto ipos = a.find('i');
        if (ipos != string::npos) bb = stoi(a.substr(ppos + 1, ipos - ppos - 1));
        return make_pair(aa, bb);
    }
};
