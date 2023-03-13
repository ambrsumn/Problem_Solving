class Solution {
public:
    string maxValue(string n, int x) 
    {
        string ans = "";
        if(n[0] != '-')
        {
            int i=0;
            
            while(i<n.length())
            {
                if(n[i]-'0' >= x)ans.push_back(n[i]);
                else
                {
                    ans.push_back(x+'0');
                    break;
                }
                i++;
            }
            
            while(i<n.length())
            {
                ans.push_back(n[i]);
                i++;
            }
            
            if(n.length() == ans.length())ans.push_back(x+'0');
        }
        
        else
        {
            ans.push_back('-');
            int i=1;
            
            while(i<n.length())
            {
                if(n[i]-'0' <= x)ans.push_back(n[i]);
                else
                {
                    ans.push_back(x+'0');
                    break;
                }
                i++;
            }
            
            while(i<n.length())
            {
                ans.push_back(n[i]);
                i++;
            }
            
            if(n.length() == ans.length())ans.push_back(x+'0');
        }
        
        return ans;
    }
};