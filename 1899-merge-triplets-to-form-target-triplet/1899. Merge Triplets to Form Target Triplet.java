class Solution {
    public boolean mergeTriplets(int[][] triplets, int[] target) {

        boolean f = false;
        boolean s = false;
        boolean t = false;

        for(int[] it : triplets)
        {
            if(it[0] == target[0] && it[1] <= target[1] && it[2] <= target[2])f = true;
            if(it[1] == target[1] && it[0] <= target[0] && it[2] <= target[2])s = true;
            if(it[2] == target[2] && it[1] <= target[1] && it[0] <= target[0])t = true;
        }

        return f && s && t;
        
    }
}