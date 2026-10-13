class Solution {
    public List<Integer> maxPrimes(int n, int s) {

        int[] all = new int[n+1];
        // List<Integer> prime = new ArrayList<>();
        int curr = 0;
        List<Integer> ans = new ArrayList<>();

        for(int i=2; i<=Math.sqrt(n); i++)
        {
            if(all[i] == 0)
            {
                for(int j=i*i; j<=n; j+=i)
                {
                    all[j] = 1;
                }
            }
        }

        for(int i=2; i<=n; i++)
        {
            if(all[i] == 0)
            {
                if((curr+i) <= s)
                {
                    ans.add(i);
                    curr += i;
                }
                else break;
            }
        }

        return ans;
    }
}
