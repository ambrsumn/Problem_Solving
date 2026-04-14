class Solution {
public:
    int mySqrt(int x) {

        int low = 0, high = x;
        int ans;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long square = (long)mid * (long)mid;

            long diff = x - square;

            if (diff == 0)
                return mid;

            if (diff > 0) {
                ans = mid;
                low = mid + 1;
            }

            else high = mid - 1;
        }

        return ans;
    }
};