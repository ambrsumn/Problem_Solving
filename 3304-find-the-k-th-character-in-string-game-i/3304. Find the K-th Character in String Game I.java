class Solution {

    public char recur(StringBuilder s, int k)
    {

        if(s.length() > k)return s.charAt(k-1);

        int n = s.length();

        for(int i=0; i<n; i++)
        {
            int curr = ((int)s.charAt(i) - 97 + 1)%26 + 97;
            s.append((char)curr);
        }

        return recur(s, k);
    }

    public char kthCharacter(int k) {
        StringBuilder str = new StringBuilder("a");
        return recur(str, k);
    }
}