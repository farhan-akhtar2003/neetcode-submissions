class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st; 
        int sz = nums.size();

        for(auto num : nums) st.insert(num);

        int ans = 0;
        for(auto x : st){ 
            int len = 1;

            if(st.find(x-1) == st.end()){
                for(int i = 1; i < sz; i++){
                    if(st.find(x+i) != st.end()) len++;
                    else break;
                }

                ans = max(ans, len);
            }
        }
        return ans;    
    }
};