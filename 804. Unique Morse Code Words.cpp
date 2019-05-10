class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> transformations;
        for (auto it = words.begin(); it != words.end(); it++) {
            string transformation;
            for (int i = 0; i < it->length(); i++) {
                transformation += morse[(*it)[i] - 97];
            }
            transformations.insert(transformation);
        }
        return transformations.size();
    }
};
