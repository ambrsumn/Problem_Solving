class Solution {

    List<String> ans;

    public void recur(int i, String s, StringBuilder curr) {
        // IO.println(i+ " " + curr);
        if (i >= s.length()) {
            ans.add(curr.toString());
            return;
        }

        int og = (int) s.charAt(i);

        if (og >= 48 && og <= 57) {
            curr.append(s.charAt(i));
            recur(i + 1, s, curr);
            curr.deleteCharAt(curr.length() - 1);
            return;
        }

        else {
            // keep same
            curr.append(s.charAt(i));
            recur(i + 1, s, curr);
            curr.deleteCharAt(curr.length() - 1);

            // order change
            int small = og + 32;
            int caps = og - 32;

            if (og < 97) {
                curr.append((char) small);
                recur(i + 1, s, curr);
                curr.deleteCharAt(curr.length() - 1);
            } else {
                curr.append((char) caps);
                recur(i + 1, s, curr);
                curr.deleteCharAt(curr.length() - 1);
            }
        }

    }

    public List<String> letterCasePermutation(String s) {
        ans = new ArrayList<>();
        StringBuilder curr = new StringBuilder("");

        recur(0, s, curr);
        return ans;
    }
}