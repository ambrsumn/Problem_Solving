class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {

        if(words.size() != s.length())return false;

        int i=0;
        for(auto it : words)
        {
            // cout<<it[0]<<" "<<s[i]<<endl;
            if(s[i] != it[0])return false;
            i++;
        }

        return true;
        
    }
};