class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> strv;
        stringstream ss(s);
        string word;

        while (ss >> word) {
            strv.push_back(word);
        }

        if (pattern.size() != strv.size()) {
            return false;
        }

        unordered_map<char, string> ctow;
        unordered_map<string, char> wtoc;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = strv[i];

            if (ctow.find(c) != ctow.end() && ctow[c] != w) {
                return false;
            }

            if (wtoc.find(w) != wtoc.end() && wtoc[w] != c) {
                return false;
            }

            ctow[c] = w;
            wtoc[w] = c;
        }

        return true;
    }
};
