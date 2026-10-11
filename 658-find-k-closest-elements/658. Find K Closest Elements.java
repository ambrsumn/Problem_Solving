class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {

        List<Integer> ans = new ArrayList<>();
        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>((a, b)->{
            if(a.getKey() == b.getKey())return Integer.compare(a.getValue(), b.getValue());
            return Integer.compare(a.getKey(), b.getKey());
        });

        for(int it : arr)pq.add(new Pair<>(Math.abs(it-x), it));

        while(k > 0)
        {
            ans.add(pq.poll().getValue());
            k--;
        }

        Collections.sort(ans);
        return ans;    
    }
}