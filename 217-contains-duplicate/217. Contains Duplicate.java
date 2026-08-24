class Solution {
    public boolean containsDuplicate(int[] nums) {

        HashMap<Integer, Integer> st  = new HashMap<>();

        for(Integer it : nums)st.put(it, st.getOrDefault(it, 0)+1);

        for(Integer it : st.keySet())
        {
            // IO.print(st.get(it) + " ");
            if(st.get(it) >= 2)return true;
        }

        if(st.size() == nums.length)return false;

        return false;
    }
}