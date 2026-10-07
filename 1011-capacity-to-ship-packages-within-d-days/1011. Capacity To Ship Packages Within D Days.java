class Solution {

    public boolean isPossible(int[] weights, int days, int target)
    {
        int totalDays = 1;
        int currSum = 0;
        for(int it : weights)
        {
            if(currSum+it <= target)currSum += it;

            else 
            {
                totalDays++;
                if(it > target)return false;
                currSum = it;
                // IO.print(currSum + " ");
            }
        }

        return totalDays <= days;
    }

    public int shipWithinDays(int[] weights, int days) {

        int low = 1, high = (int)1e8;
        int ans = Integer.MAX_VALUE;

        while(low <= high)
        {
            int mid = low + (high-low)/2;

            if(isPossible(weights, days, mid))
            {
                high = mid-1;
                ans = Math.min(ans, mid);
            }
            else low = mid+1;
        }

        return ans;

    }
}