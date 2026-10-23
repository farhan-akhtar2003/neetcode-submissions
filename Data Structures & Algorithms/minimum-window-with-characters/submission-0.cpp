class Solution {
   public:
   // TC: O(n^2.128) SC: O(n)
    bool check(string s, string t) {
        vector<int> freq(128, 0);

        for (char c : s) freq[c]++;

        for (char c : t) {
            if (freq[c] == 0) return false;
            freq[c]--;
        }

        return true;
    }

    string minWindow(string s, string t) {
        int n = s.size();
        string st = "", ans = "";
        int l = 0, minLen = INT_MAX;

        for (int r = 0; r < n; r++) {
            // add ele
            st += s[r];

            // shrink / remove ele or window for invalid case
            while (check(st, t)) {
                // update ans
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    ans = st;
                }

                st.erase(st.begin());
                l++;
            }
        }

        // update ans
        return ans;
    }
};