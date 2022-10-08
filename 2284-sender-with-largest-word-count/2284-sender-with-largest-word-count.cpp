class Solution {
public:
    
    int fun(string s)
    {
        int count=0;
        
        for(auto it : s)
            if(it == ' ')count++;
        
        return count+1;
    }
        
    string largestWordCount(vector<string>& m, vector<string>& s) 
    {
        map<string, int> mpp;
        
        for(int i=0; i<m.size(); i++)
        {
            int d = fun(m[i]);
            
            if(!mpp.count(s[i]))mpp[s[i]]=d;
            else mpp[s[i]]=mpp[s[i]]+d;
        }
        
        set<string> st;
        int def = INT_MIN;
        
        for(auto it : mpp)
        {
            if(it.second > def)
            {
                st.clear();
                st.insert(it.first);
                def = it.second;
            }
            
            else if(it.second == def)st.insert(it.first);
        }
        
        auto it = st.end();
        it--;
        
        return *it;
    }
};