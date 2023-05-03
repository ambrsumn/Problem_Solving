class Solution {
public:
    int partitionDisjoint(vector<int>& nums) 
    {
        vector<int> nxtgr;
        stack<int> st;
        st.push(nums.back());
        nxtgr.push_back(-1);
        
        for(int i=nums.size()-2; i>=0; i--)
        {
            if(!st.empty())
            {
                nxtgr.push_back(st.top());
                
                while(!st.empty() && nums[i] <= st.top())st.pop();
                
                if(st.empty())
                st.push(nums[i]);
            }
        }
        reverse(nxtgr.begin(), nxtgr.end());
        
        // for(auto it : nxtgr)cout<<it<<" ";
        // cout<<endl;
        
        int i;
        int maxi = nums[0];
        
        for(i=0; i<nums.size(); i++)
        {
            if(nxtgr[i] >= nums[i] && maxi <= nxtgr[i])break;
            
            maxi = max(maxi, nums[i]);
        }
        
        return (i+1);
        
        
    }
};