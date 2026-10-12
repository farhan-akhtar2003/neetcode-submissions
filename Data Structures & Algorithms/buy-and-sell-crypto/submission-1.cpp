class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0;
        int maxm = INT_MIN;

        for (int r = 0; r < n; r++) {
            if (prices[r] - prices[l] < 0) {
                l = r;
            }

            maxm = max(maxm, prices[r] - prices[l]);
        }

        return maxm;
    }
};
