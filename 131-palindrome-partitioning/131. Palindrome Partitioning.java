class Solution {

   public boolean isValid(List<String> curr, String s) {
        int validLength = s.length();

        for (String it : curr)
            validLength -= it.length();

        return validLength == 0 ? true : false;
    }

    public boolean isPalindrome(StringBuilder s) {
        int n = s.length();
        for (int i = 0; i < n / 2; i++)
            if (s.charAt(i) != s.charAt(n - i - 1))
                return false;

        return true;
    }

    List<List<String>> ans;

    public void recur(int i, StringBuilder curr, List<String> currList, String s) {
        int n = s.length();

        if (i >= s.length()) {
            if (isValid(currList, s)) {
                ans.add(new ArrayList<>(currList));
                return;
            }
            return;
        }

        curr.append(s.charAt(i));

        // check palin

        if (isPalindrome(curr)) {
            // add this to list and find the next.
            currList.add(curr.toString());
            StringBuilder newStr = new StringBuilder("");
            recur(i + 1, newStr, currList, s);
            currList.remove(currList.size() - 1);
        }

        // continue appending and find next

        recur(i + 1, curr, currList, s);
    }

    public List<List<String>> partition(String s) {
        ans = new ArrayList<>();
        StringBuilder curr = new StringBuilder("");
        List<String> currList = new ArrayList<>();

        recur(0, curr, currList, s);

        return ans;
    }
}