class Solution {
    int total = 0;
    int max = 0;
    Set<List<Integer>> st;

    public void recur(int i, List<Integer> prev) {

        if (prev.size() == max) {
            st.add(new ArrayList<>(prev));
            return;
        }
        if (i > total)return;

        while(i <= total)
        {
            //pick 
            prev.add(i);
            recur(i+1, prev);

            //np
            prev.remove(prev.size()-1);
            i++;
        }
    }

    public List<List<Integer>> combine(int n, int k) {

        total = n;
        max = k;
        List<Integer> curr = new ArrayList<>();
        st = new HashSet<>();

        recur(1, curr);
        return new ArrayList<>(st);
    }
}