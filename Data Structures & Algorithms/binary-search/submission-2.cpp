const auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0, h = n - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (nums[mid] == target) return mid;
            if (nums[mid] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return -1;
    }
};
