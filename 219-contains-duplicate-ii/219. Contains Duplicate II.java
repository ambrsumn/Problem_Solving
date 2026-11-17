class Solution {

    public int upperBound(List<Integer> list, int target)
    {
        int low = 0;
        int high = list.size()-1;
        int ans = -1;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if(list.get(mid) > target)
            {
                ans = list.get(mid);
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
    public boolean containsNearbyDuplicate(int[] nums, int kk) {

        Map<Integer, List<Integer>> mpp = new HashMap<>();

        for(int i=0; i<nums.length; i++)
        {
            int num = nums[i];

            mpp.computeIfAbsent(num, k-> new ArrayList<>()).add(i);
        }

        for(Integer it : mpp.keySet())
        {
            List<Integer> indexes = mpp.get(it);

            for(int i=0; i<indexes.size()-1; i++)
            {
                for(int j=i+1; j<indexes.size(); j++)
                {
                    if(indexes.get(j)-indexes.get(i) > kk)break;

                    else return true;
                }
            }
        }

        return false;
    }
}