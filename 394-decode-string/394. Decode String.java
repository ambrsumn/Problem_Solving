class Solution {

    public Pair<Integer, Integer> makeNumber(int i, String s) {
        int num = 0;
        while (i < s.length() && (int) s.charAt(i) >= 48 && (int) s.charAt(i) <= 57) {
            num = num * 10 + ((int) s.charAt(i) - 48);
            i++;
        }

        return new Pair<>(num, i-1);
    }

    public Pair<StringBuilder, Integer> recur(int i, String s) {
        int n = s.length();
        StringBuilder str = new StringBuilder("");
        int num = 0;

        for (; i < n; i++) {
            // IO.println(s.charAt(i))
            if (s.charAt(i) == ']')
                return new Pair<>(str, i);

            else if (s.charAt(i) == '[') {
                Pair<StringBuilder, Integer> ans = recur(i + 1, s);

                // IO.println(num + " " + ans.getKey() + ans.getValue());
                while(num>0)
                {
                    str.append(ans.getKey());
                    num--;
                }
                i = ans.getValue();
            }

            else if ((int) s.charAt(i) >= 48 && (int) s.charAt(i) <= 57) {
                Pair<Integer, Integer> mn = makeNumber(i, s);
                i = mn.getValue();
                num = mn.getKey();
            }
            else str.append(s.charAt(i));
        }

        return new Pair<>(str, n);
    }

    public String decodeString(String s) {

        return recur(0, s).getKey().toString();

    }
}