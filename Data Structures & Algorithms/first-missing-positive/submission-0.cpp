class Solution {
   public:
    //  nums[] < ans < nums[] or infinity
    // F F F F  ANS  T T T T ==> use binary search
    // soln 1 binary search fails as predicate is not completely monotonic for any missing int or
    // duplicate elements
    bool check(int mid, const vector<int>& nums) {
        return find(nums.begin(), nums.end(), mid) == nums.end();
    }

    int firstMissingPositive1(vector<int>& nums) {
        int l = 1;
        int h = INT_MAX;
        int ans = INT_MAX;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (check(mid, nums)) {
                ans = min(ans, mid);
                h = mid - 1;  // case is true so we need to collapse domain as we need smaller one
            } else
                l = mid + 1;  // false case so increase domain
        }
        return ans;
    }

    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visit(n + 1, false);

        for (int num : nums) {
            if (num > 0 && num <= n) visit[num - 1] = true;
        }
        for (int i = 0; i < n; i++) {
            if (visit[i] == false) return i + 1;
        }
        return n + 1;
    }
};