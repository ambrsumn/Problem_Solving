class Solution {

    TreeSet<Integer> st = new TreeSet<>();

    public void recur(int i, int num, int[] digits, ArrayList<Integer> vis, int count) {
        // IO.println("recur " + count + " " + num);
        if (count == 3) {
            if (num % 2 == 0)
                st.add(num);
            return;
        }

        for (int k = 0; k < digits.length; k++) {
            if (vis.get(k) != 1) {
                vis.set(k, 1);
                recur(k, num * 10 + digits[k], digits, vis, count + 1);
                vis.set(k, 0);
            }
        }
        return;
    }

    public int[] findEvenNumbers(int[] digits) {

        ArrayList<Integer> vis = new ArrayList<>(Collections.nCopies(digits.length, 0));
        // IO.println("length " + vis.size());

        for (int i = 0; i < digits.length; i++) {
            if (digits[i] != 0) {
                vis.set(i, 1);
                recur(i, digits[i], digits, vis, 1);
                vis.set(i, 0);
            }
        }

        // IO.println(st.size());
        // for(int it : st)IO.print(it + " ");

        int[] ans = st.stream().mapToInt(Integer::intValue).toArray();

        return ans;
    }
}