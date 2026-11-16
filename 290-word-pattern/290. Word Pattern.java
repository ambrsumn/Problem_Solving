import java.util.Collection;

class Solution {
    public boolean wordPattern(String pattern, String s) {

        StringBuilder str = new StringBuilder("");

        Map<String, Character> mpp = new HashMap<>();
        int n = pattern.length();
        int m = s.length();
        int j = 0;

        for (int i = 0; i < m; i++) {
            StringBuilder temp = new StringBuilder("");

            while (i < m && s.charAt(i) != ' ') {
                temp.append(s.charAt(i));
                i++;
            }

            String word = temp.toString();

            if (!mpp.containsKey(word)) {
                if (j == n)
                    return false;
                mpp.put(word, pattern.charAt(j));
            }
            str.append(mpp.get(word));
            j++;
        }

        Collection<Character> val = mpp.values();
        Set<Character> st = new HashSet<>(val);

        IO.println(mpp);
        return str.toString().equals(pattern) && val.size() == st.size();
    }
}