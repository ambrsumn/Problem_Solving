class Solution {
public:
    
    bool isVowel(char c)
    {
        if(c == 'a' || c=='e' || c=='i' || c=='o' || c=='u')return true;
        
        return false;
    }
    
    int vowelStrings(vector<string>& words, int left, int right) 
    {
        int ans=0;
        for(int i=left; i<=right; i++)
        {
            string temp = words[i];
            
            if(isVowel(temp[0]) && isVowel(temp[temp.length()-1]))ans++;
        }
        
        return ans;
    }
};