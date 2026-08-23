class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        string firstString = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (j < min(firstString.size(), strs[i].size())) {
                if (firstString[j] != strs[i][j]) break;
                j++;
            }
            firstString = firstString.substr(0, j);
        }
        return firstString;
    }
};