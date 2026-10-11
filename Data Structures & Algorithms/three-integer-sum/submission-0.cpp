class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 1, k = n - 1;
        sort(nums.begin(), nums.end());

        set<vector<int>> st;

        while (i < n - 2) {
            j = i + 1,k = n - 1;

            while (j < k) {
                if (nums[j] + nums[k] == -nums[i]) {
                    st.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (nums[j] + nums[k] < -nums[i]) {
                    j++;
                } else {
                    k--;
                }
            }
            i++;
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};