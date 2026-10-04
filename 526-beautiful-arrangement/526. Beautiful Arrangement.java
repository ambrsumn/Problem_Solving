class Solution {

    int recur(int i, int[] vis)
    {
        if(i > vis.length)return 1;

        int ans = 0;

        for(int k=0; k<vis.length; k++)
        {
            int curr = k+1;

            if(vis[k]==0)
            {
                if(i%curr == 0 || curr%i == 0)
                {
                    vis[k] = 1;
                    ans += recur(i+1, vis);
                    vis[k] = 0;
                }
            }
        }

        return ans;
    }
    public int countArrangement(int n) {

        int[] perm = new int[n];

        return recur(1, perm);
    }
}