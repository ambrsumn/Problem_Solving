class Solution {
    public int[][] insert(int[][] arr, int[] n) {

        List<List<Integer>> list = new ArrayList<>();

        for (int[] row : arr) {

            List<Integer> temp = new ArrayList<>();

            for (int x : row) {
                temp.add(x);
            }

            list.add(temp);

        }

        List<Integer> temp = new ArrayList<>();

        for (int x : n) {
            temp.add(x);
        }

        list.add(temp);

        Collections.sort(list, (a,b)->{
            return Integer.compare(a.get(0), b.get(0));
        });

        List<List<Integer>> mergedList = new ArrayList<>();
        // boolean lastMerged = false;

        for(int i=1; i<list.size(); i++)
        {
            if(list.get(i-1).get(1) >= list.get(i).get(0))
            {
                list.get(i).set(0, list.get(i-1).get(0));
                list.get(i).set(1, Math.max(list.get(i-1).get(1), list.get(i).get(1)));
                // lastMerged = true;
            }
            else 
            {
                mergedList.add(list.get(i-1));
                // lastMerged = false;
            }
        }
        // if(lastMerged == true)
        // {
            mergedList.add(list.get(list.size()-1));
        // }

        int[][] ans = new int[mergedList.size()][2];
        int i=0;
        for(List<Integer> it : mergedList)
        {
            ans[i][0] = it.get(0);
            ans[i][1] = it.get(1);

            i++;
        }

        // IO.println(mergedList);
        return ans;
    }
}