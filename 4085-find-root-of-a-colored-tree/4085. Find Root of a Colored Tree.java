class Solution {
    public int findColoredRoot(int[][] edges, String colors) {

        int n = colors.length();
        int[] eligibleNodes = new int[n]; // 0 are eligible one's
        Map<Integer, List<Pair<Integer, Character>>> graph = new HashMap<>();

        for (int[] it : edges) {
            int node1 = it[0];
            int node2 = it[1];

            graph.computeIfAbsent(node1, k -> new ArrayList<>()).add(new Pair<>(node2, colors.charAt(node2)));

            graph.computeIfAbsent(node2, k -> new ArrayList<>()).add(new Pair<>(node1, colors.charAt(node1)));

            List<Pair<Integer, Character>> child = null;

            if (eligibleNodes[node1] == 0) {
                child = graph.get(node1);

                if (child.size() > 2)
                    eligibleNodes[node1] = 1;

                else if (child.size() > 1 && child.get(0).getValue() != child.get(1).getValue())
                    eligibleNodes[node1] = 1;
            }

            if (eligibleNodes[node2] == 0) {
                child = graph.get(node2);

                if (child.size() > 2)
                    eligibleNodes[node2] = 1;

                else if (child.size() > 1 && child.get(0).getValue() != child.get(1).getValue())
                    eligibleNodes[node2] = 1;
            }
        }

        Deque<Pair<Integer, Character>> q = new ArrayDeque<>();
        StringBuilder col;
        int[] visited = new int[n];

        

        for(int i=0; i<n; i++)
        {
            if(eligibleNodes[i] != 0)continue;            
            boolean isInvalid = false;
            q.clear();
            int stamp = i+1;

            char init = colors.charAt(i);

            if(init == 'R')col = new StringBuilder("RBW");
            else if(init == 'B')col = new StringBuilder("BWR");
            else if(init == 'W')col = new StringBuilder("WRB");
            else col = new StringBuilder("WRB");

            q.addLast(new Pair<>(i, init));
            visited[i] = stamp;

            int depth = 0;

            while(!q.isEmpty())
            {
                int currSize = q.size();
                depth = (depth + 1)%3;

                while(currSize > 0)
                {
                    Pair<Integer, Character> top = q.poll();
                    int count = 0;

                    for(Pair<Integer, Character> nodes : graph.get(top.getKey()))
                    {
                        int node = nodes.getKey();
                        char color = nodes.getValue();

                        if(visited[node] != stamp)
                        {
                            if(count > 2 || color != col.charAt(depth))
                            {
                                isInvalid = true;
                                break;
                            }

                            q.addLast(new Pair<>(node, color));
                            visited[node] = stamp;
                        }

                        count++;
                    }

                    if(isInvalid)break;

                    currSize--;
                }

                if(isInvalid)break;
            }

            if(isInvalid)continue;
            return i;
        }

        return -1;
    }
}