class Solution {

    public double recur(String curr, String end, 
    Map<String, List<Pair<String, Double>>> graph, Map<String, Boolean> visited)
    {
        // //IO.println(curr + " " + end);
        if(curr.equals(end))return 1.0;
        // if(visited.get(curr) == true)
        // {
        //     // //IO.println("return 0");
        //     return -1.0;
        // }

        double ans = -1.0;
        visited.put(curr, true);

        List<Pair<String, Double>> paths = graph.get(curr);
        // //IO.println(curr + " " + end + " " + paths.size());

        for(Pair<String, Double> path : paths)
        {
            //IO.println("looping");
            if(visited.get(path.getKey()) == false)
            {
                ans = path.getValue() * recur(path.getKey(), end, graph, visited);
                //IO.println(ans + " " + path.getKey() + " " + path.getValue());
                if(ans > 0)
                {
                    visited.put(curr, false);
                    return ans;
                }
            }
        }

        visited.put(curr, false);
        return ans > 0 ? ans : -1;
    }
    public double[] calcEquation(List<List<String>> e, double[] v, List<List<String>> q) {

        Map<String, List<Pair<String, Double>>> graph = new HashMap<>();
        Map<String, Boolean> visited = new HashMap<>();
        double[] ans = new double[q.size()];

        // create graph
        for (int i=0; i<e.size(); i++) {
            List<String> it = e.get(i);

            graph.computeIfAbsent(it.get(0), k -> new ArrayList<>()).add(new Pair<>(it.get(1), v[i]));
            graph.computeIfAbsent(it.get(1), k -> new ArrayList<>()).add(new Pair<>(it.get(0), 1.0 / v[i]));

            visited.putIfAbsent(it.get(0), false);
            visited.putIfAbsent(it.get(1), false);
        }

        for(int i=0; i<q.size(); i++)
        {
            String st = q.get(i).get(0);
            String end = q.get(i).get(1);
                ans[i] = -1.0;

            if(visited.containsKey(st) == false || visited.containsKey(end) == false)continue;

            //IO.println(st + " " + end);
            //IO.println(visited);
            ans[i] = recur(st, end, graph, visited);
            //IO.println(visited);
        }

        return ans;
    }
}