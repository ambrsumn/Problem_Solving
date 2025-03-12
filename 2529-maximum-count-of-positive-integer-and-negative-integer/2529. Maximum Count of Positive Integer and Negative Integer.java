class Solution {
    public int maximumCount(int[] nums) {

        // int n = nums.size();
        int pos = 0;
        int neg = 0;

        for(Integer it : nums)
        {
            if(it>0)pos++;
            if(it < 0)neg++;
        }

        return Math.max(pos, neg);
        
    }
}