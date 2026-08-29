class Solution {

    int lower(List<Integer> nums, int target) {

        int low = 0;
        int high = nums.size()-1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums.get(mid) >= target) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }

        return ans;
    }

    int upper(List<Integer> nums, int target) {

        int low = 0;
        int high = nums.size()-1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // IO.print(mid + " " + nums.get(mid) + " " + target);
            if (nums.get(mid) <= target) {
                ans = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }

        return ans;
    }

    public int maxVowels(String s, int k) {

        int n = s.length();
        ArrayList<Integer> v = new ArrayList<>();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'a' || s.charAt(i) == 'e' ||
                    s.charAt(i) == 'i' || s.charAt(i) == 'o' ||
                    s.charAt(i) == 'u') {
                v.add(i);
            }
        }

        int st = 0;

        while (st <= n - k) {
            int l = st;
            int u = st + k - 1;

            int left = lower(v, l);
            int right = upper(v, u);
            if (left != -1 && right != -1) {
                ans = Math.max(ans, (right - left+1));
            }

            st++;

        }

        return ans;

    }
}