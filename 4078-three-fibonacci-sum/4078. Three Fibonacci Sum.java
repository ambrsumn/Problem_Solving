class Solution {
    public boolean threeFibonacciSum(int n) {

        if(n%2 == 1)return false;

        int x = 0, y = 1;
        int t = 0;

        while(t < n/2)
        {
            t = x + y;
            x = y;
            y = t;
        }

        if(t == n/2)return true;
        return false;
    }
}