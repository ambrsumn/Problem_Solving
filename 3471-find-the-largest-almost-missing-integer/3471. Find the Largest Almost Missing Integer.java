class Solution {
    public int largestInteger(int[] nums, int k) {

        int n = nums.length;
        int i = 0, j = 0;
        int ans = -1;
        HashMap<Integer, Integer> mpp = new HashMap();
        HashSet<Integer> st = new HashSet();
        int count = 0;

        while (j < n) {
            if (j - i + 1 == k) {
                IO.println(j + " " + i + " ---- ");

                for (int l = i; l <= j; l++)st.add(nums[l]);

                for(int it : st)
                {
                    IO.println(mpp.getOrDefault(it, 0));
                    mpp.put(it, mpp.getOrDefault(it, 0)+1);
                    IO.println(it + " " + mpp.getOrDefault(it, 0));
                }
                st.clear();
                // mpp.put(nums[i], mpp.get(nums[i])-1);
                i++;
            }

            j++;
        }

        for (int it : mpp.keySet()) {
            // IO.println(it + " " + mpp.get(it));
            if (mpp.get(it) == 1)
                ans = Math.max(ans, it);
        }

        return ans;
    }
}