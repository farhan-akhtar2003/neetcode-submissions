class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0;
        int maxm = INT_MIN;

        for (int r = 0; r < n; r++) {
            if (prices[r] - prices[l] < 0) {
                l = r; // basically it means sell price is less than buy price so greedly u will take the most cheapest one to buy price for more benefits
            }

            maxm = max(maxm, prices[r] - prices[l]);
        }

        return maxm;
    }
};
