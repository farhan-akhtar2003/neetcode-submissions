class Solution {
   public:
    string encode(vector<string>& strs) {
        string s = "";

        for (string& str : strs) {
            s.push_back((char)str.size());
            s += str;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        for (int i = 0; i < s.size(); i++) {
            int sz = s[i];
            ans.push_back(s.substr(i + 1, sz));
            i += sz;
        }
        return ans;
    }
};