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

                for (int l = i; l <= j; l++)st.add(nums[l]);

                for(int it : st)
                {
                    IO.println(mpp.getOrDefault(it, 0));
                    mpp.put(it, mpp.getOrDefault(it, 0)+1);
                    IO.println(it + " " + mpp.getOrDefault(it, 0));
                }
                st.clear();
                i++;
            }

            j++;
        }

        for (int it : mpp.keySet()) {
            if (mpp.get(it) == 1)
                ans = Math.max(ans, it);
        }

        return ans;
    }
}