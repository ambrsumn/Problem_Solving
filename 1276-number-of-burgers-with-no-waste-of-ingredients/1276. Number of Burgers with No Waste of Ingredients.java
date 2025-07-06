class Solution {
    public List<Integer> numOfBurgers(int t, int c) {

        List<Integer> ans = new ArrayList<>();
        if(t == 0 && c == 0)
        {
            ans.add(0);
            ans.add(0);
            return ans;
        }

        if(t <= c)return ans;
        if(t%2 != 0)return ans;

        int small=0;

        if(t == 2*c)
        {
            ans.add(0);
            ans.add(c);
            return ans;
        }

        if(t == 4*c)
        {
            ans.add(c);
            ans.add(0);
            return ans;
        }

        while(c >= 1 && t >= 4)
        {
            small++;
            t -= 4;
            c--;

            if(t == 2*c)
            {
                ans.add(small);
                ans.add(c);
                return ans;
            }
        }

        return ans;

    }
}