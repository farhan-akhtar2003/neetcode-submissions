class Solution {
public:
/*
=========================================APPROACH=======================================
1. Assume mid is ship capacity per day. Start with reqDay = 1 and currWeight = mid.
2. Traverse weights in given order. If package exceeds remaining capacity, start next day and reset currWeight = mid.
3. If reqDay > days, capacity is insufficient → return false.
4. Load package by subtracting weights[i] from currWeight.
5. All packages fit within allowed days → return true.
tc: O(nlog(sum of Weights))
====================================END OF APPROACH=====================================
*/
    bool predicate(vector<int>& weights, int days, int mid){
        int n=weights.size();
        int reqDay = 1, currWeight = mid;
        for (int i = 0; i < n; i++) {
            if(currWeight - weights[i] <0){
                reqDay++;
                if(reqDay > days) return false;
                currWeight = mid; // reset capacity means in given mid weight some boxes get acquired
            }
            currWeight -= weights[i];;
        }

        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int h = accumulate(weights.begin(), weights.end(), 0);

        int ans = INT_MAX;
        while(l<=h){
            int mid = l + (h-l)/2;
            if (predicate(weights, days, mid)) {
                ans = min(ans, mid);
                h = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};