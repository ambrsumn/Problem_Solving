class Solution {
    public int minDeletions(int[] nums) {

        Stack<Integer> st = new Stack<>();

        for(int it : nums)
        {
            if(st.isEmpty() || st.peek() != it)st.add(it);

            // IO.println(it + " " + st.size());
        }

        return nums.length - st.size();
        
    }
}