class Solution {
   public:
    /*
 =========================================APPROACH=======================================
 1. Find pivot (minimum element index) using binary search.
 2. Predicate: nums[mid] <= nums[n-1] identifies right sorted half.
 3. If predicate is true, store mid and search left for earlier valid index; otherwise, search
 right.
 4. Apply normal binary search on left sorted half [0, pivot-1].
 5. If target not found, apply binary search on right sorted half [pivot, n-1].
 6. Return target index if found, otherwise -1.
 // TC: O(logN), SC: 0(1)
 ====================================END OF APPROACH=====================================
 */
    bool predicate(vector<int>& nums, int mid) {
        int n = nums.size();
        return nums[mid] <= nums[n - 1];
    }

    int findPivot(vector<int>& nums) {
        int l = 0, h = nums.size() - 1;

        int ans = INT_MAX;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (predicate(nums, mid)) {
                ans = min(ans, mid);
                h = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }

    bool binarySearch(int l, int h, vector<int>& nums, int target) {
        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (nums[mid] == target) return true;
            if (nums[mid] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return false;
    }

    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int pivot = findPivot(nums);

        bool present = binarySearch(0, pivot - 1, nums, target);
        if (!present) present = binarySearch(pivot, n - 1, nums, target);
        return present;
    }
};
