class Solution {
    public List<String> summaryRanges(int[] nums) {

        List<String> ans = new ArrayList<>();

        int i = 0;
        int n = nums.length;

        while (i < n) {
            int st = nums[i];
            while (i + 1 < n && nums[i + 1] <= nums[i] + 1)
                i++;

            int end;
            if (i == nums.length)
                end = nums[nums.length - 1];
            else
                end = nums[i];

            StringBuilder str = new StringBuilder("");

            if (st != end) {
                str.append(Integer.toString(st));
                str.append("->");
                str.append(Integer.toString(end));
            }
            else str.append(Integer.toString(st));

            ans.add(str.toString());

            i++;
        }

        return ans;
    }
}