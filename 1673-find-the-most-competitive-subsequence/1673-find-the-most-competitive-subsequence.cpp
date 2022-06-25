class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) 
    {
        vector<int> ans;
        stack<int> st;
        int n = nums.size();
        
        int d = n-k;
        
        for(int i=0; i<n; i++)
        {
            int pos;
            if(d >= i)
                pos = 0;
            else
                pos = i-d;
            
            // cout<<pos<<" "<<i<<" ";
            
            while(!st.empty() && st.top()>nums[i] && st.size()>pos)
            {
                // cout<<" y ";
                st.pop();
            }
            
            st.push(nums[i]);
            // cout<<endl;
        }
        
        while(st.size() > k)
            st.pop();
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};