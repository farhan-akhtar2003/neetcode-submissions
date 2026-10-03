class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;  // Prefix sum 0 occurs once before starting array, so sum 0 -exists atleast 1-> 

        int prefixSum = 0, ans = 0;

        for (auto x : nums) {
            prefixSum += x;

            // If previous prefix sum = prefixSum - k,
            // then subarray between that prefix and current prefix has sum k.
            if (freq.count(prefixSum - k)>0) {
                // Same prefix sum can occur multiple times,
                // so each occurrence gives one valid subarray.
                ans += freq[prefixSum - k];
            }

            // Store current prefix sum for future subarrays.
            freq[prefixSum]++;
        }

        return ans;
    }
};