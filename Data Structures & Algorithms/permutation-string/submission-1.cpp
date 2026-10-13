class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        multiset<char> st1(s1.begin(), s1.end());
        int n = s2.size(), m = s1.size();

        if (m > n) return false;
        multiset<char> st;

        for (int ind = 0; ind < n; ind++) {
            int new_end = ind;
            int old_start = ind - m;

            // Add new char
            st.insert(s2[new_end]);

            // Remove old char only when window exceeds m size.
            if (old_start >= 0) {
                st.erase(st.find(s2[old_start]));
            }

            // update ans
            if (ind >= m - 1 && st == st1) return true;
        }

        return false;
    }
};