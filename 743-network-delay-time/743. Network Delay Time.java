class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {

        int ans = Integer.MIN_VALUE;
        int[] time = new int[n];
        for(int i=0; i<n; i++)time[i] = Integer.MAX_VALUE;

        List<List<Pair<Integer, Integer>>> graph = new ArrayList<>();

        for(int i=0; i<n; i++)graph.add(new ArrayList<>());

        for(int[] it : times)
        {
            graph.get(it[0]-1).add(new Pair<>(it[1]-1, it[2]));
        }

        // IO.println(graph);

        time[k-1] = 0;
        Deque<Pair<Integer, Integer>> q = new ArrayDeque<>();
        q.addFirst(new Pair<>(k-1, 0));

        while(q.isEmpty() == false)
        {
            int currSize = q.size();

            while(currSize > 0)
            {
                Pair<Integer, Integer> pr = q.removeFirst();
                // IO.println(parent);
                int parent = pr.getKey();
                int parentCost = pr.getValue();

                for(Pair<Integer, Integer> child : graph.get(parent))
                {
                    int childNode = child.getKey();
                    int totalTime = parentCost + child.getValue();

                    if(time[childNode] > totalTime)
                    {
                        time[childNode] = totalTime;
                        q.addLast(new Pair<>(childNode, totalTime));
                    }
                }

                currSize--;
            }
        }

        for(int it : time)ans = Math.max(ans, it);

        return ans == Integer.MAX_VALUE ? -1 : ans;

    }
}