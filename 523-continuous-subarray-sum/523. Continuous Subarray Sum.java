class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {

        HashMap<Integer, Integer> mpp = new HashMap<>();

        mpp.put(0, -1);
        int curr = 0;
        int i = 0;

        for (Integer it : nums) {
            curr = (curr + it) % k;

            if (curr < 0) {
                int x = (int) Math.ceil((double) curr / k);
                curr += k * x;
            }

            if (mpp.containsKey(curr)) {
                int idx = mpp.get(curr);
                int len = (i - idx);

                IO.println(len + " " + curr + " " + idx);

                if(len >= 2)return true;
            }

            if (!mpp.containsKey(curr))
                mpp.put(curr, i);
            i++;
        }

        return false;

    }
}