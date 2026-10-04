class Solution {
   public:
    bool isPalindrome(string s) {
        string ss;

        for (auto x : s) {
            if (isalnum(x)) ss += tolower(x);
        }

        string rev = ss;
        reverse(rev.begin(), rev.end());
        return ss == rev;
    }
};