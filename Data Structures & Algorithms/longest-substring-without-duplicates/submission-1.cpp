class Solution {
   public:
    //    Complexity: O(nlogk) time, O(k) space, where k = distinct chars tracked.
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;

        int maxm = 0;
        map<char, int> mp;
        for (int r = 0; r < n; r++) {
            // insert current ele
            mp[s[r]]++;

            // decrease window due to duplicate ele.
            while (mp[s[r]] > 1) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) mp.erase(s[l]);  // freq -> 0 remove it
                l++;
            }

            // update ans
            maxm = max(maxm, r - l + 1);  // r-l+1 => window size
        }

        return maxm;
    }
};
