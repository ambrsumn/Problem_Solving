class Solution {

    public boolean isSquare(int[] sides) {
        // for(int it : sides)IO.print(it + " ");
        // IO.println();

        for (int i = 1; i < 4; i++)
            if (sides[i] != sides[0])
                return false;
        return true;
    }

    public boolean recur(int i, int[] sides, int[] ms, int sideLen) {
        if (i >= ms.length) {
            if (isSquare(sides))
                return true;
            return false;
        }

        boolean ans = false;

        for (int k = 0; k < 4; k++) {
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

    public boolean makesquare(int[] ms) {

        int[] sides = new int[4];
        Arrays.sort(ms);

        for (int i = 0, j = ms.length - 1; i < j; i++, j--) {
            int temp = ms[i];
            ms[i] = ms[j];
            ms[j] = temp;
        }
        int totalLen = 0;
        for (int it : ms)
            totalLen += it;

        if (totalLen % 4 != 0)
            return false;
        int sideLen = totalLen / 4;

        return recur(0, sides, ms, sideLen);
    }
}