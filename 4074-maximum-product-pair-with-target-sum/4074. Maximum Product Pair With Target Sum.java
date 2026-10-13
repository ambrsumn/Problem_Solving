class Solution {
    public int[] maxProductPair(int[] nums, int target) {
        
        int[] ans = new int[2];
        ans[0] = -1;
        ans[1] = -1;
        
        int pro = Integer.MIN_VALUE;

        List<Pair<Integer, Integer>> sorted = new ArrayList<>();

        for(int i=0; i<nums.length; i++)sorted.add(new Pair<>(nums[i], i));

        Collections.sort(sorted, (a,b)->{
            return Integer.compare(a.getKey(), b.getKey());
        });

        IO.println(sorted);

        int i=0, j=sorted.size();

        for(int k=0; k<j-1; k++)
        {
            for(int l=k+1; l<j; l++)
            {
                int a = sorted.get(k).getKey();
                int b = sorted.get(l).getKey();

                int ai = sorted.get(k).getValue();
                int bi = sorted.get(l).getValue();

                if(a != b && a+b == target)
                {
                    int curr = a*b;

                    if(curr > pro)
                    {
                        ans[0] = a > b ? ai : bi;
                        ans[1] = ans[0] == ai ? bi : ai;
                    }
                }

            }
        }

        return ans;
    }
}

