class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        stack<int> st;
        int n = num.size();
        
        for(int i=0; i<n; i++)
        {
            // cout<<i<<" ";
            while(!st.empty() && st.top() > num[i] && k>0)
            {
                // cout<<"y ";
                st.pop();
                k--;
            }
            
            st.push(num[i]);
            
            if(st.size() == 1 && st.top() == '0')
                st.pop();
            // cout<<endl;
        }
        
        while(k>0)
        {
            if(st.empty())
                break;
            
            st.pop();
            k--;
        }
        
        string ans = "";
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        if(ans.size() == 0)
            ans.push_back('0');
        
        return ans;
    }
};