class Solution {
    public int search(int[] nums, int target) {
        
        int n = nums.length-1;
        int i = 0, j = n;

        while(i <= j)
        {
            int mid = i + (j-i)/2;
            if(nums[mid] == target)return mid;

            if(nums[mid] < target)i = mid+1;
            else j = mid-1;
        }

        return -1;
    }
}