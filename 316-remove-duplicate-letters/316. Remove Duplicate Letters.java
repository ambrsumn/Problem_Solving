class Solution {
    public String removeDuplicateLetters(String s) {

        HashMap<Character, Integer> mpp = new HashMap<>();

        for (int i = 0; i < s.length(); i++)
            mpp.put(s.charAt(i), mpp.getOrDefault(s.charAt(i), 0) + 1);
        Stack<Character> st = new Stack<>();
        Set<Character> stt = new HashSet<>();

        for (int i = 0; i < s.length(); i++) {
            char curr = s.charAt(i);

            if (!stt.contains(curr)) {
                while (!st.isEmpty() && st.peek() > curr && mpp.get(st.peek()) != 0) {
                    // mpp.put(st.pop(), mpp.get(curr)-1);
                    stt.remove(st.pop());
                }

                st.add(curr);
                mpp.put(curr, mpp.get(curr) - 1);
                stt.add(curr);
            }
            else 
            {
                mpp.put(curr, mpp.get(curr) - 1);
            }

            // IO.println(st);
        }

        StringBuilder str = new StringBuilder("");

        while (!st.isEmpty())
            str.append(st.pop());
        str.reverse();

        return str.toString();
    }
}