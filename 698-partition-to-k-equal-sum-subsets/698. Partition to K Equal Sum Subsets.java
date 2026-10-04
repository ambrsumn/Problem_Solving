class Solution {

    public boolean isValid(int[] sides) {

        for (int i = 1; i < sides.length; i++)
            if (sides[i] != sides[0])
                return false;
        return true;
    }

    public boolean recur(int i, int[] sides, int[] ms, int sideLen) {
        if (i >= ms.length) {
            if (isValid(sides))
                return true;
            return false;
        }

        boolean ans = false;

        for (int k = 0; k < sides.length; k++) {
            // choose this side if eligible

            if (sides[k] + ms[i] <= sideLen) {
                sides[k] += ms[i];
                ans = ans || recur(i + 1, sides, ms, sideLen);
                // skip this side
                sides[k] -= ms[i];
            }
        }

        return ans;

    }

    public boolean canPartitionKSubsets(int[] ms, int k) {

        int[] sides = new int[k];
        Arrays.sort(ms);

        for (int i = 0, j = ms.length - 1; i < j; i++, j--) {
            int temp = ms[i];
            ms[i] = ms[j];
            ms[j] = temp;
        }
        int totalLen = 0;
        for (int it : ms)
            totalLen += it;

        if (totalLen % k != 0)
            return false;
        int sideLen = totalLen / k;

        return recur(0, sides, ms, sideLen);
    }
}