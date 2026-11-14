class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] indegree = new int[numCourses];
        int[] ans = new int[numCourses];
        int idx=0;
        Map<Integer, List<Integer>> mpp = new HashMap<>();

        for (int[] req : prerequisites) {
            indegree[req[0]]++;
            mpp.computeIfAbsent(req[1], k -> new ArrayList<>()).add(req[0]);
        }

        Deque<Integer> q = new ArrayDeque<>();

        for (int i = 0; i < indegree.length; i++)
            if (indegree[i] == 0)q.addLast(i);

        while (!q.isEmpty()) {
            int currSize = q.size();

            while (currSize > 0) {
                int top = q.removeFirst();
                ans[idx] = top;
                idx++;

                // IO.println(top);

                if (mpp.get(top) != null) {
                    // IO.println(mpp.get(top));
                    for (Integer it : mpp.get(top)) {

                        indegree[it]--;
                        if (indegree[it] == 0)
                            q.addLast(it);
                    }
                }

                currSize--;
            }
        }

        for (int it : indegree)
            if (it > 0)
                return new int[0];
        return ans;
    }
}