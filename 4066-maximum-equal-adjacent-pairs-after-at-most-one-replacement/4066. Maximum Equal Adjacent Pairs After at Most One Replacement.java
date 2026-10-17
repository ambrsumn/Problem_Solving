import java.util.*;
import java.io.*;

class Solution {
    public int maxEqualAdjacentPairs(int[] nums) {

        Map<List<Integer>, Integer> mpp = new HashMap<>();
        int n = nums.length;
        int ans = Integer.MIN_VALUE;
        int same = 0;

        for(int i=0; i<n-1; i++)
        {
            List<Integer> curr = Arrays.asList(Math.min(nums[i], nums[i+1]), Math.max(nums[i], nums[i+1]));
            mpp.put(curr, mpp.getOrDefault(curr, 0)+1);

            ans = Math.max(mpp.get(curr), ans);

            if(nums[i] == nums[i+1])same++;
        }

        // System.out.println("same " + same);
        // System.out.println(mpp);

        for(List<Integer> key : mpp.keySet())
        {
            int nums1 = key.get(0);
            int nums2 = key.get(1);

            if(nums1 == nums2)
            {
                // System.out.println("same key " + nums1 + " " + nums2);
                continue;
            }
            int currAns = mpp.get(key) + same;
            // System.out.println(nums1 + " " + nums2 + " " + currAns + " " + same);

            ans = Math.max(ans, currAns);
        }

        return ans;
    }
}
