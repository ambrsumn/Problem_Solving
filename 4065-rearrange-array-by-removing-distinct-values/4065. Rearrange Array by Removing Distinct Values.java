import java.util.*;
import java.io.*;

class Solution {
    public int[] rearrangeArray(int[] nums) {

        List<Integer> ans = new ArrayList<>();
        Map<Integer, Integer> mpp = new TreeMap<>();

        for(int it : nums)mpp.put(it, mpp.getOrDefault(it, 0)+1);
        // System.out.println(mpp);

        while(ans.size() != nums.length)
        {
            // System.out.println(ans + " <- ans size");
            for(Integer key : mpp.keySet())
            {
                if(mpp.get(key) > 0)
                {
                    // System.out.println(key + " " + mpp.get(key));
                    ans.add(key);
                    mpp.put(key, mpp.get(key)-1);
                }
            }
        }
        int i=0;
        // System.out.println(ans);
        for(Integer it : ans)
        {
            nums[i] = it;
            // System.out.print(nums[i] + " ");
            i++;
        }

        return nums;
    }
}
