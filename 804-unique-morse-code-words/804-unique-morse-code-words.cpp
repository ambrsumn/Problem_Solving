class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        set<string> st;
        string codes[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        
        for(int i=0; i<words.size(); i++)
        {
            string sample = "";
            // cout<<word[i]
            for(int j=0; j<words[i].length(); j++)
            {
                sample += codes[words[i][j]-97];
            }
            st.insert(sample);
        }
        
        return st.size();
    }
};