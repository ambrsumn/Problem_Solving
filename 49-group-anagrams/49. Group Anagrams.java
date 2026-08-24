class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> n = new ArrayList<>();
        HashMap<String, ArrayList<Integer>> mpp = new HashMap<>();

        int i=0;
        for(String it : strs)
        {
            char[] arr = it.toCharArray();
            Arrays.sort(arr);

            String sorted = new String(arr);

            if(!mpp.containsKey(sorted))mpp.put(sorted, new ArrayList<>());
            mpp.get(sorted).add(i);
            i++;
        }

        for(String key : mpp.keySet())
        {
            ArrayList<Integer> curr = mpp.get(key);
            ArrayList<String> temp = new ArrayList<>();

            for(Integer it : curr)
            {
                temp.add(strs[it]);
            }

            n.add(temp);
        }

        return n;
    }
}