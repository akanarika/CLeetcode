/*
 * @lc app=leetcode id=271 lang=cpp
 *
 * [271] Encode and Decode Strings
 */

// @lc code=start
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string s = "";
        for (auto str : strs) {
            s += to_string(str.length()) + ":" + str;
        }
        return s;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        istringstream in(s);
        int l;
        string str = "";
        while (in >> l) {
            in.get();
            char c;
            while (--l >= 0) {
                c = in.get();
                str += c;
            }
            res.push_back(str);
            str = "";
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
// @lc code=end
