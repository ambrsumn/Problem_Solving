class Solution {
    public int pivotIndex(int[] nums) {

        int curr = 0;
        ArrayList<Integer> preSum = new ArrayList<>();

        for(Integer it : nums)
        {
            curr += it;
            preSum.add(curr);
        }

        for(int i=0; i<nums.length; i++)
        {
            int left = i>0 ? preSum.get(i-1) : 0;
            int right = preSum.get(nums.length-1)-preSum.get(i);

            if(left == right)return i;
        }

        return -1;
    }
}