class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char>stk;
        for(int i=0;i<s.length();i++)
        {
            if(stk.empty()==true)
            {
                stk.push(s[i]);
            }
            else if(stk.empty()==false)
            {
                if(stk.top()==s[i])
                {
                    stk.pop();
                }
                else
                {
                    stk.push(s[i]);
                }
            }
        }
        string ans="";
        while(!stk.empty())
        {
            ans=stk.top()+ans;
            stk.pop();
        }
        return ans;
    }
};