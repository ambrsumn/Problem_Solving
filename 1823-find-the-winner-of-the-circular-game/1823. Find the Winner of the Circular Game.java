class Solution {
    public int findTheWinner(int n, int k) {

        ArrayList<Integer> f = new ArrayList<>();

        for(int i=1; i<=n; i++)f.add(i);
        int curr = 0;

        while(f.size() != 1)
        {
            int toRemove = (curr + k - 1)%f.size();
            f.remove(toRemove);

            curr = toRemove%f.size();
        }     

        return f.get(0);
    }
}