class Solution {
    public int maxNumberOfFamilies(int k, int[][] arr) {
        Arrays.sort(arr, (a, b) -> Integer.compare(a[0], b[0]));
        HashMap<Integer, HashSet<Integer>> mpp = new HashMap();
        int ans = k * 2;
        int n = arr.length;

        for (int i = 0; i < n; i++) {
            if (arr[i][1] >= 2 && arr[i][1] <= 9) {
                if (mpp.containsKey(arr[i][0]))
                    mpp.get(arr[i][0]).add(arr[i][1]);
                else {
                    mpp.put(arr[i][0], new HashSet<>());
                    mpp.get(arr[i][0]).add(arr[i][1]);
                }
            }
        }

        for (int it : mpp.keySet()) {
            ans -= 2;
            HashSet<Integer> st = mpp.get(it);

            //check left
            if (!st.contains(2) && !st.contains(3) && !st.contains(4) && !st.contains(5)) {
                ans++;
                continue;
            }

            // check middle

            if (!st.contains(4) && !st.contains(5) && !st.contains(6) && !st.contains(7)) {
                ans++;
                continue;
            }

            //check right
            if (!st.contains(6) && !st.contains(7) && !st.contains(8) && !st.contains(9)) {
                ans++;
                continue;
            }

            // IO.println(ans + " " + it);
        }

        return ans;
    }
}