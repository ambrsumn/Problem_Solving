class Solution {
    public String simplifyPath(String path) {

        Deque<StringBuilder> st = new ArrayDeque<>();
        int n = path.length();

        for (int i = 0; i < n;) {
            if (path.charAt(i) == '/') {
                while (!st.isEmpty() && st.peekLast().toString().equals("/"))
                    st.removeLast();
                st.addLast(new StringBuilder("/"));
                while (i < n && path.charAt(i) == '/')
                    i++;
            }

            // IO.println(i + " " + st);

            StringBuilder temp = new StringBuilder("");
            while (i < n && path.charAt(i) != '/') {
                temp.append(path.charAt(i));
                i++;
            }

            IO.println("temp " + temp);

            if (temp.toString().equals("..")) {

                IO.println("before " + st);
                if (!st.isEmpty())
                    st.removeLast();
                if (!st.isEmpty())
                    st.removeLast();

                    if(st.isEmpty())st.addLast(new StringBuilder("/"));

                IO.println("after " + st);
            } else if (!temp.toString().equals(".") && !temp.toString().equals("")) {
                // IO.println("---");
                st.addLast(new StringBuilder(temp));
                // IO.println("-- " + st);
            }
            // IO.println(i + " " + st + " " + temp);
            if (i == path.length() - 1)
                break;

        }

        IO.println("STACK - " + st);
        if(st.size()>1 && st.peekLast().toString().equals("/"))st.removeLast();
        StringBuilder ans = new StringBuilder("");
        while (!st.isEmpty())
            ans.append(st.removeFirst());

        return ans.toString();

    }
}