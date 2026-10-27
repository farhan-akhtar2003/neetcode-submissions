const auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// Approach 2: Flatten 2D matrix into 1D array and apply binary search.
// TC: O(log(m*n)), SC: O(1)
//
// Matrix has m rows and n columns. Each row contains n elements.
// idx / n → row index: count complete rows passed.
// idx % n → column index: leftover elements in current row.
// Example: idx = 6, n = 4 → row = 1, col = 2 → matrix[1][2].
// m * n → total elements in matrix.
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int m = matrix.size();

        int l = 0, r = m * n - 1;  // last idx of 1d will be m*n-1

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[mid / n][mid % n] == target)
                return true;
            else if (matrix[mid / n][mid % n] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};

// Approach 1: TC:O(m+n) SC:O(1)
class Solution1 {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int m = matrix.size();

        int i = 0, j = n - 1;  // start from 1st last corner element
        while (i < m && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                j--;  // greater so target may exists in same row just decrease column no
            else
                i++;  // smaller so target may be at next depth aka next row .
        }

        return false;
    }
};
