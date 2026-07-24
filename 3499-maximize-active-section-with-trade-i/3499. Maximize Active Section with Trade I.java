class Solution {

    public int lowerBound(ArrayList<Integer> arr, int target) {
        int low = 0, high = arr.size() - 1;
        int ans = Integer.MAX_VALUE;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr.get(mid) >= target) {
                if (arr.get(mid) == target)
                    ans = Math.min(ans, mid);
                high = mid - 1;
            } else if (arr.get(mid) < target) {
                low = mid + 1;
            }
        }

        return ans;

    }

    public int upperBound(ArrayList<Integer> arr, int target) {
        int low = 0, high = arr.size() - 1;
        int ans = Integer.MAX_VALUE;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr.get(mid) <= target) {
                low = mid + 1;
            } else if (arr.get(mid) > target) {
                ans = Math.min(ans, mid);
                high = mid - 1;
            }
        }

        return Math.min(ans, arr.size());
    }

    public int maxActiveSectionsAfterTrade(String s) {

        ArrayList<Integer> arr = new ArrayList<>();
        ArrayList<Integer> pre = new ArrayList<>();
        int ans = 0;
        int currSum = 0;
        int convertible = 0;

        for(char it : s.toCharArray())if(it == '1')ans++;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '0')
                arr.add(0);

            else {
                int j = i;

                while (j + 1 < s.length() && s.charAt(j + 1) == '1') {
                    j++;
                }

                arr.add(1);
                i = j;
            }

            currSum += arr.get(arr.size() - 1);
            pre.add(currSum);
        }

        for (int i = 0; i < pre.size(); i++) {
            if ((i == 0 && pre.get(i) == 1) || (i > 0 && pre.get(i) > pre.get(i - 1))) {
                int lower = lowerBound(pre, pre.get(i) - 1);
                int upper = upperBound(pre, pre.get(i)) - 1;

                if (pre.get(i) > 1)
                    lower += 1;

                if (lower == i || upper == i)
                    continue;
                int curr = (upper - lower);
                convertible = Math.max(convertible, curr);
            }
        }

        return ans + convertible;
    }
}