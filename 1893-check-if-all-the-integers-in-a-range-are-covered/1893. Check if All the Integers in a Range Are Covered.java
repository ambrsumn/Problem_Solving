class Solution {
    public boolean isCovered(int[][] ranges, int left, int right) {

        int[] preSum = new int[52];

        int n = ranges.length;

        for(int i=0; i<n; i++)
        {
            preSum[ranges[i][0]] += 1;
            preSum[ranges[i][1]+1] -= 1;
        }

        for(int i=1; i<52; i++)preSum[i] += preSum[i-1];

        for(int i=left; i<=right; i++)if(preSum[i] <= 0)return false;

        return true;
        
    }
}