class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {

        int n = gas.length;

        int curr = 0;
        int preSum = 0;
        int st = 0;

        for(int i=0; i<n; i++)
        {
            int need = gas[i] - cost[i];
            curr += need;
            preSum += need;

            if(curr < 0)
            {
                st = i+1;
                curr = 0;
            }
        }

        if(preSum < 0)return -1;

        return st;
    }
}