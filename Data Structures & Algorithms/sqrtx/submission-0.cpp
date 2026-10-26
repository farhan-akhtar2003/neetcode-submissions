const auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
   public:
    int mySqrt(int x) {
        int l = 1;
        int h = x / 2;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (mid * mid == x)
                return mid;
            else if (mid * mid < x)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return h;
    }
};