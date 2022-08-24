class Solution {
public:
    int n=0,o=0,c=0;
    vector<string> ans;
    
    void bt(string temp)
    {
        if(temp.size() == (2*n))
        {
            ans.push_back(temp);
            return;
        }
        
        if(o<n)
        {
            o++;
            temp.push_back('(');
            bt(temp);
            temp.pop_back();
            o--;
        }
        
        if(o>c)
        {
            c++;
            temp.push_back(')');
            bt(temp);
            temp.pop_back();
            c--;
        }
    }
    vector<string> generateParenthesis(int t) 
    {
        n=t;
        bt("");
        
        return ans;
    }
};