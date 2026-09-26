class Solution {

    public void recur(int i, char[] s)
    {
        if(i > (s.length/2)-1)return;

        int target = (s.length - i - 1);
        char t = s[target];
        s[target] = s[i];
        s[i] = t;

        recur(i+1, s);
    }

    public void reverseString(char[] s) {
        recur(0, s);
    }
}