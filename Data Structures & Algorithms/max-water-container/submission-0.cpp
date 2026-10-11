class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0, j = n - 1;
        int amnt = 0;

        while (i < j) {
            int l = j - i;
            int b = min(heights[i], heights[j]);
            amnt = max(amnt, l * b);

            if (heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }
        }

        return amnt;
    }
};