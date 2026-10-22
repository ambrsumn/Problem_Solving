class Solution {
    public int monotoneIncreasingDigits(int n) {

        Stack<Character> st = new Stack<>();
        String str = String.valueOf(n);
        StringBuilder ans = new StringBuilder("");


        for(int i=0; i<str.length(); i++)
        {
            char c = str.charAt(i);

            if(st.isEmpty())st.add(c);

            else if(st.peek() <= c)st.add(c);

            else 
            {
                char toProcess = c;
                while(!st.isEmpty() && st.peek() > toProcess)
                {
                    toProcess = (char)(st.pop()-1);
                    // IO.println("toProcess " + toProcess);
                }

                while(!st.isEmpty())ans.append(st.pop());

                ans.reverse();
                ans.append((char)(toProcess));

                int pending = str.length() - ans.length();

                while(pending > 0)
                {
                    ans.append('9');
                    pending--;
                }

                // IO.println(ans);
                return Integer.parseInt(ans.toString());

            }
        }

        return n;
        
    }
}