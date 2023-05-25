class Solution {
public:
    int minLength(string s) 
    {
        stack<char> st;
        
        for(auto it : s)
        {
            if(it == 'D')
            {
                if(!st.empty() && st.top() == 'C')st.pop();
                else st.push('D');
            }
            
            else if(it == 'B')
            {
                if(!st.empty() && st.top() == 'A')st.pop();
                else st.push('B');
            }
            
            else st.push(it);
        }
        
        return st.size();
    }
};