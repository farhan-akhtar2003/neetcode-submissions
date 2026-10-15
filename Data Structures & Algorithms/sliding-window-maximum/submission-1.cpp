class Solution {
   public:
    // 1st approach :: using mulitset: TC: O(nlogk) SC: O(k)
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     int n = nums.size();

    //     vector<int> ans;
    //     multiset<int> st;
    //     for (int ind = 0; ind < n; ind++) {
    //         int new_end = ind;
    //         int old_start = ind - k;

    //         // add ele to window
    //         st.insert(nums[ind]);

    //         // remove old start ele if window size exceed k
    //         if (old_start >= 0) st.erase(st.find(nums[old_start]));

    //         // update the ans and window
    //         if (ind - k + 1 >= 0) ans.push_back(*st.rbegin());
    //     }

    //     return ans;
    // }

    // 2nd approach :: using deque: TC: O(n) SC: O(k)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans;
        deque<int> maxDq;  // maxDeque keeps track of the maximum values in the current window in
                           // decreasing order.

        for (int ind = 0; ind < n; ind++) {
            int new_end = ind;
            int old_start = ind - k;

            // add ele to window
            while (!maxDq.empty() && nums[maxDq.back()] <= nums[ind])
                maxDq.pop_back();  // New value ≥ back value → remove back. New value dominates old
                                   // one: it is larger and expires later.
            maxDq.push_back(ind);

            // shrink/remove expired ele from the window
            if (!maxDq.empty() && maxDq.front() <= old_start) maxDq.pop_front();

            // update ans
            if (ind - k + 1 >= 0) ans.push_back(nums[maxDq.front()]);
        }

        return ans;
    }
};
