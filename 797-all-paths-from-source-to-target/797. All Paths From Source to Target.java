class Solution {

    List<List<Integer>> ans;

    public void recur(int curr, int[] visited, int[][] graph, List<Integer> currPath) {
        if (curr == graph.length-1) {
            currPath.add(curr);
            ans.add(new ArrayList<>(currPath));
            currPath.remove(currPath.size()-1);
            return;
        }
        visited[curr] = 1;
        currPath.add(curr);

        for (Integer it : graph[curr]) {
            if (visited[it] == 0) {
                recur(it, visited, graph, currPath);

            }
        }

        visited[curr] = 0;
        currPath.remove(currPath.size() - 1);

        return;
    }

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {

        int[] visited = new int[graph.length];
        List<Integer> currPath = new ArrayList<>();
        ans = new ArrayList<>();

        recur(0, visited, graph, currPath);

        return ans;
    }
}