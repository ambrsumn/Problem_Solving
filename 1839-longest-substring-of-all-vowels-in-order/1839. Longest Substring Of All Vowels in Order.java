class Solution {
    int lastProcessed = -1;

    public boolean isValid(char curr, char prev)
    {
        if(prev == ' ' || curr == prev)return true;

        return (prev == 'a' && curr == 'e' || 
        prev == 'e' && curr == 'i' ||
        prev == 'i' && curr == 'o' ||  
        prev == 'o' && curr == 'u'
        );
    }

    public int recur(int i, char prev, String word)
    {
        if(i >= word.length())
        {
            if(prev == 'u')return 0;
            return Integer.MIN_VALUE;
        }
        if(word.charAt(i) != 'u' && prev == 'u')return 0;

        if(!isValid(word.charAt(i), prev))return Integer.MIN_VALUE;

        lastProcessed = Math.max(i, lastProcessed);
        return 1 + recur(i+1, word.charAt(i), word);

    }
    public int longestBeautifulSubstring(String word) {

        int ans = 0;
        for(int i=0; i<word.length(); i++)
        {
            if(word.charAt(i) == 'a')
            {
                ans = Math.max(ans, recur(i, ' ', word));
                i = lastProcessed;
            }
        }

        return ans;
        
    }
}