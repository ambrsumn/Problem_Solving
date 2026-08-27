class Solution {
    public List<List<Long>> splitPainting(int[][] s) {

        Long mini = Long.MAX_VALUE;
        Long maxi = Long.MIN_VALUE;
        int n = s.length;
        List<List<Long>> ans = new ArrayList<>();
        Set<Integer> st = new TreeSet<>();

        for (int i = 0; i < n; i++) {
            mini = Math.min(mini, s[i][0]);
            maxi = Math.max(maxi, s[i][1]);

            st.add(s[i][0]);
            st.add(s[i][1]);
        }

        long[] preSum = new long[(int)(maxi + 1)];
        List<Integer> ranges = new ArrayList<>(st);

        for (int i = 0; i < n; i++) {
            int l = s[i][0];
            int r = s[i][1];
            int val = s[i][2];

            preSum[l] += (long)val;
            preSum[r] -= (long)val;
        }

        for (int i = 1; i <= maxi; i++)
            preSum[i] += (long)preSum[i - 1];

        for (int i = 0; i < ranges.size() - 1; i++) {

            List<Long> temp = new ArrayList<>();

            int str = ranges.get(i);
            int ed = ranges.get(i + 1);
            Long val = preSum[str];

            if (val != 0) {
                temp.add((long) str);
                temp.add((long) ed);
                temp.add((long) val);

                ans.add(temp);
            }
        }

        // int i = mini;
        // while(i < maxi)
        // {
        //     int curr = preSum[i];
        //     int prev = i;

        //     while(i<=maxi && curr == preSum[i])i++;

        //     temp.add((Long)prev);
        //     temp.add((Long)i);
        //     temp.add((Long)curr);

        //     ans.add(temp);
        // }

        return ans;
    }
}