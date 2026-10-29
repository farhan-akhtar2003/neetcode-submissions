class Solution {
   public:
    /*
 =========================================APPROACH=======================================
 1. Use binary search on indices [0, n-1].
 2. Predicate: nums[mid] <= nums[n-1] means mid lies in sorted right half,
    which contains minimum. Otherwise, mid lies in left half.
 3. If predicate is true, store min mid and search left side for earlier valid index.
 4. Otherwise, search right. Return nums[ans].
 TC: O(logn), SC: O(1)
 ====================================END OF APPROACH=====================================
 */
    bool predicate(vector<int>& nums, int mid) {
        int n = nums.size();
        return nums[mid] <= nums[n - 1];
    }

    int findMin(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int h = n - 1;

        int ans = INT_MAX;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (predicate(nums, mid)) {
                ans = min(ans, mid);
                h = mid - 1;
            } else
                l = mid + 1;
        }
        return nums[ans];
    }
};