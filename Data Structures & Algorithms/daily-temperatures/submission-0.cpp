class Solution {
   public:
    /*
 =========================================APPROACH=======================================
 1. Maintain monotonic decreasing stack storing {temperature, index} of days awaiting warmer
 temperature.
 2. For each day, while current temperature > stack top temperature, pop previous day and set
 ans[index] = current index - previous index.
 3. Push current {temperature, index}. Unresolved days remain 0 because no warmer day exists.
 TC: O(n) SC: O(n)
 ====================================END OF APPROACH=====================================
 */
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> sc;
        int n = temperatures.size();

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int currTemp = temperatures[i];

            while (!sc.empty() && sc.top().first < currTemp) {
                int idx = sc.top().second;  // prevLowest temp
                sc.pop();
                ans[idx] = i - idx;  // idx will be the index of prevLowest temp
            }
            sc.push({currTemp, i});
        }
        return ans;
    }
};