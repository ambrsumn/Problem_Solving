class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {

        int[] preSum = new int[n];

        int k = bookings.length;

        for(int i=0; i<k; i++)
        {
            int from = bookings[i][0]-1;
            int to = bookings[i][1];
            int b = bookings[i][2];

            preSum[from] += b;

            if(to < n)preSum[to] -= b;
        }

        for(int i=1; i<n; i++)preSum[i] += preSum[i-1];

        return preSum;
    }
}