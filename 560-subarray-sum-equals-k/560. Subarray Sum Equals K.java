class Solution {

    public int binarySearch(ArrayList<Integer> arr, Integer idx) {
        int i = 0, j = arr.size() - 1;
        int ans = Integer.MAX_VALUE;

        while (i <= j) {
            int mid = i + (j - i) / 2;

            if (arr.get(mid) < idx) {
                i = mid+1;
            } else {
                ans = Math.min(ans, mid);
                j = mid - 1;
            }

        }

        // IO.println(arr.size() + " " + ans);

        if (ans == Integer.MAX_VALUE)
            return -1;

        return arr.size() - ans;
    }

    public int subarraySum(int[] nums, int k) {

        ArrayList<Integer> arr = new ArrayList<>();
        int curr = 0;
        int ans = 0;
        HashMap<Integer, ArrayList<Integer>> mpp = new HashMap<>();

        int i = 0;
        for (Integer it : nums) {
            curr += it;
            arr.add(curr);

            if (mpp.containsKey(curr)) {
                mpp.get(curr).add(i);
            } else {
                mpp.put(curr, new ArrayList<>());
                mpp.get(curr).add(i);
            }
            i++;
        }

        for (i = 0; i < arr.size(); i++) {
            int left = 0;
            if (i > 0)
                left = arr.get(i - 1);

            int rem = k + left;

            if (mpp.containsKey(rem)) {
                int currAns = binarySearch(mpp.get(rem), i);
                IO.println(rem + " " + i + " " + ans);
                if(currAns != -1)ans += currAns;
            }
        }

        return ans;

    }
}