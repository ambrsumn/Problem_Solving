class Solution {

    HashSet<String> ans;

    public void recur(int open, int close, int n, StringBuilder s) {
        if (open + close == 2 * n && open == close) {
            ans.add(s.toString());
            return;
        }

        if (open < n) {
            s.append('(');
            recur(open + 1, close, n, s);
            s.deleteCharAt(s.length() - 1);
        }
        if (close < open) {
            s.append(')');
            recur(open, close + 1, n, s);
            s.deleteCharAt(s.length() - 1);
        }
        if (close == open && open < n) {
            s.append('(');
            s.append(')');
            recur(open + 1, close + 1, n, s);
            s.deleteCharAt(s.length() - 1);
            s.deleteCharAt(s.length() - 1);
        }
        return;
    }

    public List<String> generateParenthesis(int n) {

        StringBuilder s = new StringBuilder("");
        ans = new HashSet<>();
        recur(0, 0, n, s);

        return new ArrayList<>(ans);
    }
}