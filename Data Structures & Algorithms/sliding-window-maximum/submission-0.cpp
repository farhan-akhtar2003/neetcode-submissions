class Solution {
   public:
    // using mulitset: TC: O(nlogk) SC: O(k)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans;
        multiset<int> st;
        for (int ind = 0; ind < n; ind++) {
            int new_end = ind;
            int old_start = ind - k;

            // add ele to window
            st.insert(nums[ind]);

            // remove old start ele if window size exceed k
            if (old_start >= 0) st.erase(st.find(nums[old_start]));

            // update the ans and window
            if (ind - k + 1 >= 0) ans.push_back(*st.rbegin());
        }

        return ans;
    }
};
