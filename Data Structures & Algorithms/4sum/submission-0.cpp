class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0, j = 1, k = 2, l = n - 1;

        while (i < n - 3) {
            j = i + 1;
            while (j < n - 2) {
                k = j + 1, l = n - 1;

                while (k < l) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target) {
                        st.insert({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                    } else if (sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
                j++;
            }
            i++;
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};