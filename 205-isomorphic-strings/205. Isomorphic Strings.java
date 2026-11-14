class Solution {
    public boolean isIsomorphic(String s, String t) {

        if(s.length() != t.length())return false;

        Map<Character, Character> mpp = new HashMap<>();

        StringBuilder str = new StringBuilder("");

        for(int i=0; i<s.length(); i++)
        {
            char curr = s.charAt(i);
            if(mpp.containsKey(curr))
            {
                str.append(mpp.get(curr));
                continue;
            }

            else 
            {
                char mapper = t.charAt(i);
                for(char it : mpp.values())
                    if(it == mapper)return false;

                mpp.put(curr, mapper);
                str.append(mapper);
            }
        }

        return str.toString().equals(t);
    }
}