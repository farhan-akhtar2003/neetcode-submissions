class Solution {
   public:
   // try to find the formula for a water at that particular index
    int trap(vector<int>& height) {
        int n = height.size();

        // leftMax[i] = maximum height from index 0 to i.
        // rightMax[i] = maximum height from index i to n-1.
        vector<int> leftMax(n), rightMax(n);

        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int amnt = 0;
        // Water at each index = min(left max, right max) - current height.
        for (int i = 0; i < n; i++) amnt += min(leftMax[i], rightMax[i]) - height[i];

        return amnt;
    }
};