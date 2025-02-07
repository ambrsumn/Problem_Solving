class Solution {
public:
    bool isSubsequence(string s, string t) 
    {

        if(s == "")return true;
        queue<char> q1, q2;

        for(auto it : s)q1.push(it);
        for(auto it : t)q2.push(it);

        while(!q1.empty())
        {
            char search = q1.front();
            

            while(!q2.empty())
            {
                if(q2.front() != search)
                {
                    
                    q2.pop();
                }
                else
                {
                    q1.pop();
                    q2.pop();
                    break;
                }
            }

            if(q2.empty() && !q1.empty())return false;
        }

        if(q1.empty() )return true;
        return false;
    }
};