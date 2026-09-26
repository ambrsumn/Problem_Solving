class Solution {

    List<String> ans = new ArrayList<>();

    public String createIp(StringBuilder[] ip) {
        StringBuilder str = new StringBuilder("");
        for (int i = 0; i < 4; i++) {
            str.append(ip[i]);
            if (i != 3)
                str.append(".");
        }

        return str.toString();
    }

    public boolean isValidIp(StringBuilder[] ip, String s) {
        int totalChars = 0;
        for (int i = 0; i < 4; i++) {
            totalChars += ip[i].length();
            StringBuilder str = ip[i];
            if (str.length() == 0)
                return false;

            int curr = 0;
            int val = 0;

            while (curr < str.length()) {
                val = val * 10 + ((int) str.charAt(curr) - 48);
                curr++;
            }

            if (val > 255)
                return false;
        }
        if (totalChars != s.length())
            return false;

        return true;
    }

    public boolean isInvalidSegmentInIp(StringBuilder[] ip) {
        // ////IO.println();
        for (int i = 0; i < 4; i++) {
            StringBuilder str = ip[i];
            // if(str.length() == 0)return true;

            if(str.length() > 1 && str.charAt(0) == '0')return true;

            int curr = 0;
            int val = 0;

            while (curr < str.length()) {
                // ////IO.println(((int)str.charAt(curr) - 48));
                val = val * 10 + ((int) str.charAt(curr) - 48);
                curr++;
            }

            if (val > 255) {
                ////IO.println(" invalid");

                return true;
            }
        }
        return false;
    }

    public void recur(int i, String s, int curr, StringBuilder[] ip) {
        // //IO.println("input " + i + " " + s + " " + curr);
        // for (StringBuilder it : ip)
        //     //IO.print(it + " . ");
        // //IO.println();

        if (isInvalidSegmentInIp(ip)) {
            //IO.println("invalid");
            return;
        }
        if (isValidIp(ip, s)) {
            //IO.println("BINGOOOOOO");
            ans.add(createIp(ip));
            return;
        }
        if (i >= s.length()) {
            //IO.println("break");
            return;
        }

        while (i < s.length()) {
            // //IO.print(i + " " + curr + " " + ip[curr] + " ------>>>>>.     ");

            ip[curr].append(s.charAt(i));

            // for (StringBuilder it : ip)
            //     //IO.print(it + " . ");
            // //IO.println();

            recur(i + 1, s, curr, ip);

            ip[curr].deleteCharAt(ip[curr].length() - 1);

            if (curr < 3) {

                curr++;

                ip[curr].append(s.charAt(i));
                recur(i + 1, s, curr, ip);
                ip[curr].deleteCharAt(ip[curr].length() - 1);

                curr--;

            }

            i++;
        }
        return;
    }

    public List<String> restoreIpAddresses(String s) {

        StringBuilder[] ip = new StringBuilder[4];
        for (int i = 0; i < 4; i++)
            ip[i] = new StringBuilder("");

        recur(0, s, 0, ip);
        return ans;
    }
}