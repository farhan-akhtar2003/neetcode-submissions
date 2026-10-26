class Solution {
   public:
    int mySqrt(int x) {
        int l = 1;
        int h = x / 2 + 1;  // edge case if x = 1 then root -> 1 but x/2 makes h=0

        while (l <= h) {
            int mid = l + (h - l) / 2;
            long long square = 1LL * mid * mid; // care of integer overflow

            if (square == x)
                return mid;
            else if (square < x)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return h; // search ends when l > h. h will be largest number whose square ≤ x -> floor square root.
    }
};