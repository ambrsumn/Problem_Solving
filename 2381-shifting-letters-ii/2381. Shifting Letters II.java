class Solution {
    public String shiftingLetters(String s, int[][] shifts) {

        int n = shifts.length;
        StringBuilder str = new StringBuilder(s);

        int[] preSum = new int[s.length()];

        for (int i = 0; i < n; i++) {
            if (shifts[i][2] == 0) {
                preSum[shifts[i][0]] -= 1;

                if (shifts[i][1] + 1 < s.length())
                    preSum[shifts[i][1]+1] += 1;
            }

            else {
                preSum[shifts[i][0]] += 1;
                if (shifts[i][1] + 1 < s.length())
                    preSum[shifts[i][1]+1] -= 1;
            }
        }

        for (int i = 1; i < s.length(); i++)
            preSum[i] += preSum[i - 1];

        for (int i = 0; i < s.length(); i++) {
            int curr = (s.charAt(i) - 'a' + preSum[i] + 26)%26;

            if(curr < 0)curr += 26* (int)Math.ceil((double)(-1*curr)/26);

            curr += 97;

            char nw = (char)curr;

            str.setCharAt(i, nw);
        }

        return str.toString();

    }
}