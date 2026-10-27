class Solution {
   public:
   /*
=========================================APPROACH=======================================
1. Binary search eating speed from 1 to max pile.
2. Calculate required hours as sum of ceil(pile / mid).
3. If hours <= h, update minimum ans and search smaller speed; otherwise search larger speed.
TC: O(nlogM)), M = max(piles) , SC: O(1)
====================================END OF APPROACH=====================================
*/
    bool predicate(vector<int> piles, int mid, int h) {
        int n = piles.size();
        int hoursTaken = 0;

        for (int i = 0; i < n; i++) {
            hoursTaken += ceil((double)piles[i] / mid);
            if (hoursTaken > h) return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        int ans = INT_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (predicate(piles, mid, h)) {
                ans = min(ans, mid);
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};
