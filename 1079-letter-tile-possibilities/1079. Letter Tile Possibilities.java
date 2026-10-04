class Solution {

    Set<String> ans;

    public void recur(int i, StringBuilder curr, String tiles, int[] vis)
    {
        if(curr.length() != 0)ans.add(curr.toString());

        for(int k=0; k<tiles.length(); k++)
        {
            if(vis[k] == 0)
            {
                vis[k] = 1;
                curr.append(tiles.charAt(k));
                recur(k+1, curr, tiles, vis);
                curr.deleteCharAt(curr.length()-1);
                vis[k] = 0;
            }
        }

    }

    public int numTilePossibilities(String tiles) {

        ans = new HashSet<>();
        StringBuilder curr = new StringBuilder("");
        int[] vis = new int[tiles.length()];

        recur(0, curr, tiles, vis);

        return ans.size();
    }
}