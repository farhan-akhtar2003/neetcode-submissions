class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int p = 0;
        for (int num : nums) {
            if (num != val) {
                nums[p] = num;
                p++;
            }
        }
        return p;
    }
};