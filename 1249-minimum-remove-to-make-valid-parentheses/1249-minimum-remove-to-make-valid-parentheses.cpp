class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<pair<char, int>> st;
        set<int> stt;
        string ans="";
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '(')
                st.push({'(', i});
            
            else if(s[i] == ')')
            {
                if(!st.empty() && st.top().first == '(')
                    st.pop();
                
                else
                    st.push({')', i});
            }
        }
        
        while(!st.empty())
        {
            pair<char,int> pr;
            pr = st.top();
            st.pop();
            
            stt.insert(pr.second);
        }
        
        // for(auto it : stt)
        //     cout<<it<<" ";
        // cout<<endl;
        
        
        
        for(int i=0; i<s.length(); i++)
        {
            if((s[i]=='(' || s[i]==')') && stt.find(i) == stt.end())
            {
                // cout<<"YES "<<i<<endl;
                ans.push_back(s[i]);
            }
            
            else if(s[i] != '(' && s[i] != ')')
                ans.push_back(s[i]);
        }
        
        return ans;
    }
};