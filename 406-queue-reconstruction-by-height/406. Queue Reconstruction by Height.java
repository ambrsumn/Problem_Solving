class Solution {
    public int[][] reconstructQueue(int[][] people) {
        
        int[][] ans = new int[people.length][2];
        List<Deque<List<Integer>>> inDegree = new ArrayList<>(people.length);

        for(int i=0; i<people.length; i++)inDegree.add(new ArrayDeque<>());

        for(int[] arr : people)inDegree.get(arr[1]).addFirst(new ArrayList<>(Arrays.asList(arr[0], arr[1], arr[1])));

        int currSize = 0;

        PriorityQueue<List<Integer>> pq = new PriorityQueue<>((a,b)->Integer.compare(a.get(0), b.get(0)));
        Deque<List<Integer>> it = inDegree.get(0);
        
        while(it.size() > 0)pq.add(it.removeFirst());

        while(pq.size() > 0)
        {
            List<Integer> top = pq.poll();

            int height = top.get(0);
            int order = top.get(1);

            ans[currSize][0] = height;
            ans[currSize][1] = order;
            currSize++;

            for(int i=1; i<inDegree.size(); i++)
            {
                Deque<List<Integer>> pr = inDegree.get(i);
                int size = pr.size();

                while(size > 0)
                {
                    List<Integer> topp = pr.removeFirst();
                    int h = topp.get(0);
                    int o = topp.get(1);
                    int curr = topp.get(2);

                    if(height >= h)curr--;
                    if(curr == 0)pq.add(new ArrayList<>(Arrays.asList(h, o, curr)));
                    else inDegree.get(i).addLast(new ArrayList<>(Arrays.asList(h, o, curr)));

                    size--;
                }
            }
        }

        return ans;
    }
}