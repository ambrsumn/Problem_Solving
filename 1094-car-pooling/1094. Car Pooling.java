class Solution {
    public boolean carPooling(int[][] trips, int capacity) 
    {
        int[] preSum = new int[1001];

        int n = trips.length;

        for(int i=0; i<n; i++)
        {
            int people = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];

            preSum[from] += people;
            preSum[to] -= people;
        }

        for(int i=1; i<1001; i++)preSum[i] += preSum[i-1];

        for(Integer it : preSum)if(it > capacity)return false;
        return true;
    }
}