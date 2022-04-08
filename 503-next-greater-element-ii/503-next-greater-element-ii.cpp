class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n = nums.size();
        
        vector<int> ans;
        stack<int> st;
        
        for(int i=(n-1); i>=0; i--)
        {
            st.push(nums[i]);
        }
        
        for(int i=(n-1); i>=0; i--)
        {
            if(st.empty())
            {
                ans.push_back(-1);
                st.push(nums[i]);
            }
            
            else if(st.top() > nums[i])
            {
                ans.push_back(st.top());
                st.push(nums[i]);                
            }
            
            else if(nums[i] >= st.top())
            {
                while(!st.empty())
                {
                    st.pop();
                    
                    if(st.empty())
                    {
                        ans.push_back(-1);
                        st.push(nums[i]);
                        break;
                    }
                    
                    else if(st.top() > nums[i])
                    {
                      ans.push_back(st.top());
                      st.push(nums[i]); 
                        break;
                    }                    
                }
            }
        }
        
        // if(req != -1)
        // {
        //     ans[0] = req;
        // }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};