class Solution {

    public void recur(int i, 
    Set<String> ans, 
    Map<Integer, Set<Integer>> graph, 
    List<List<String>> a,
    int[] visited)
    {
        visited[i] = 1;

        for(int j=1; j<a.get(i).size(); j++)ans.add(a.get(i).get(j));

        for(Integer it : graph.get(i))
        {
            if(visited[it] == 0)recur(it, ans, graph, a, visited);
        }
    }
    public List<List<String>> accountsMerge(List<List<String>> a) {
        List<List<String>> ans = new ArrayList<>();

        Map<String, Set<Integer>> emails = new HashMap<>();
        Map<Integer, Set<Integer>> graph = new HashMap<>();
        Set<String> temp = new TreeSet<>();
        List<String> tempList = new ArrayList<>();

        for(int i=0; i<a.size(); i++)
        {
            for(int j=1; j<a.get(i).size(); j++)
            {
                emails.computeIfAbsent(a.get(i).get(j), k -> new HashSet<>()).add(i);
            }
        }

        int[] visited = new int[a.size()];

        for(int i=0; i<a.size(); i++)
        {
            graph.put(i, new HashSet<>());

            for(int j=1; j<a.get(i).size(); j++)
            {
                Set<Integer> indexes = emails.get(a.get(i).get(j));

                for(Integer it : indexes)graph.get(i).add(it);
            }
        }

        for(int i=0; i<visited.length; i++)
        {
            if(visited[i] == 0)
            {
                temp.clear();
                tempList.clear();
                tempList.add(a.get(i).get(0));
                recur(i, temp, graph, a, visited);

                for(String it : temp)tempList.add(it);

                ans.add(new ArrayList<>(tempList));
            }
        }

        return ans;

    }
}