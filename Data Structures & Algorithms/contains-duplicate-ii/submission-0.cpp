class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = 0;
        unordered_set<int> st;
        bool ans = false;

        for (int r = 0; r < nums.size(); r++) {
            // Window size <= k + 1.
            while (abs(r - l) > k) {
                st.erase(nums[l]);  // Remove leftmost element
                l++;
            }

            // Duplicate exists ==> means its count in set > 1.
            if (st.count(nums[r])) {
                ans = true;
                break;
            }

            st.insert(nums[r]);  // Add current element
        }

        return ans;
    }
};