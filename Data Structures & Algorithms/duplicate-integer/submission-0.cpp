class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> st;
        for (int num : nums) st.insert(num);
        return (st.size() == nums.size()) ? false : true;
    }
};