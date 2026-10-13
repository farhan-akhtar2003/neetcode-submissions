class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;

        int minm = n;
        int sum = 0;
        for (int r = 0; r < n; r++) {
            // Add ele to window.
            sum += nums[r];

            // Shrink while sum is valid.
            while (sum >= target) {
                minm = min(minm, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }

        return minm == n && accumulate(nums.begin(), nums.end(), 0LL) < target ? 0 : minm;
    }
};