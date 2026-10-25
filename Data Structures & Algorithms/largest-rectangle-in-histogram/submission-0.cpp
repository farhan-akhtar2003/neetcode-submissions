// Approach-1 (Brute Force): TC: O(5n) , SC: O(4n)
class Solution1 {
   public:
    vector<int> findNSE(vector<int> arr) {
        vector<int> ans(arr.size());
        stack<int> sc;  // continuously decreasing
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!sc.empty() && arr[sc.top()] >= arr[i]) sc.pop();

            ans[i] = sc.empty() ? arr.size() : sc.top();  // no nse --> assign array size
            sc.push(i);
        }
        return ans;
    }

    vector<int> findPSE(vector<int> arr) {
        vector<int> ans(arr.size());
        stack<int> sc;  // continuously increasing
        for (int i = 0; i < arr.size(); i++) {
            while (!sc.empty() && arr[sc.top()] >= arr[i]) sc.pop();

            ans[i] = sc.empty() ? -1 : sc.top();  // no pse --> assign -1
            sc.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);
        int maxmArea = INT_MIN;

        for (int i = 0; i < heights.size(); i++) {
            maxmArea = max(maxmArea, heights[i] * (nse[i] - pse[i] - 1));
        }

        return maxmArea;
    }
};

// Approach-2 (In a single PASS): TC: O(n) , SC: O(n)
/*
=========================================APPROACH=======================================
1. Maintain an increasing monotonic stack of indices → gives us PSE from stack
top.
2. When smaller element appears, it becomes NSE for elements popped from stack →
now we have both NSE and PSE, so compute answer.
3. If elements remain in stack after traversal, NSE = n (array size). If no PSE
exists, PSE = -1.
====================================END OF
APPROACH=====================================
*/
class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int maxmArea = INT_MIN;
        stack<int> sc;  // monotonically increasing stack

        for (int i = 0; i < heights.size(); i++) {
            while (!sc.empty() && heights[sc.top()] > heights[i]) {
                auto prevEle = sc.top();
                sc.pop();

                int nse = i;
                int pse = sc.empty() ? -1 : sc.top();

                maxmArea = max(maxmArea, heights[prevEle] * (nse - pse - 1));
            }
            sc.push(i);
        }
        // remaining elements if any in stack need to be computed for area
        while (!sc.empty()) {
            int prevEle = sc.top();
            sc.pop();

            int nse = heights.size();
            int pse = sc.empty() ? -1 : sc.top();

            maxmArea = max(maxmArea, heights[prevEle] * (nse - pse - 1));
        }

        return maxmArea;
    }
};
