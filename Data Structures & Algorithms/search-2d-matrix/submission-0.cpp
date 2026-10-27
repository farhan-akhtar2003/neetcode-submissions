const auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
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
