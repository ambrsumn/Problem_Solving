class Solution {
public:
    int maxProfit(vector<int>& p) 
    {
        stack<int> st;
        vector<int> vec;
        int n = p.size();
        
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && st.top()>=p[i])st.pop();
            
            if(st.empty())
            st.push(p[i]);
            
            vec.push_back(st.top());
        }
        
        int ans = 0;
        
        // for(auto it: vec)
        //     cout<<it<<" ";
        // cout<<endl;
        
        for(int i=n-1; i>=0; i--)
        {
            int curr = p[i]-vec.back();
            
            ans = max(ans, curr);
            vec.pop_back();
        }
        
        return ans;
    }
};