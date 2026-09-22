class Solution {

    // public void recur(int curr, ArrayList<Integer> f, int k)
    // {
    //     if(f.size() == 1)return;

    //     int n = f.size();
    //     int eliminated = (f.get(curr) + k - 1)%f.size();

    //     if(eliminated == 0)f.remove(f.size()-1);
    //     else f.remove(eliminated-1);

    //     f.remove(Math.abs(eliminated-1));
    // }
    public int findTheWinner(int n, int k) {

        ArrayList<Integer> f = new ArrayList<>();

        for(int i=1; i<=n; i++)f.add(i);

        // recur(0, f);

        // return f.get(0);   

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