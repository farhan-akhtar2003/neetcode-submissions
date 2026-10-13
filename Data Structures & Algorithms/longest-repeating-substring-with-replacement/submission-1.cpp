class Solution {
   public:
   // Complexity: \(O(26n)=O(n)\) time, \(O(1)\) space.
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;

        vector<int> vec(26, 0);
        int maxm = 0;
        for (int r = 0; r < n; r++) {
            // add ele
            vec[s[r] - 'A']++;

            // remove / shrink while replacements exceed k.
            int maxmCnt = *max_element(vec.begin(), vec.end());
            while (r - l + 1 - maxmCnt > k) {  // window size - maxCnt shall be less than K for
                                               // replacement else shrink invalid case
                vec[s[l] - 'A']--;
                l++;
                maxmCnt = *max_element(vec.begin(), vec.end());
            }

            // update ans
            maxm = max(maxm, r - l + 1);
        }

        return maxm;
    }
};
