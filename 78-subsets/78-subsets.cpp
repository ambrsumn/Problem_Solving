class Solution {
public:
    
    set<vector<int>> st;
    void bt(vector<int> &temp, int i, vector<int>& nums)
    {
        st.insert(temp);
        if(i>=nums.size())return;
        
        temp.push_back(nums[i]);
        bt(temp,i+1,nums);
        temp.pop_back();
        
        bt(temp,i+1,nums);
    }
    
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        
        for(int i=0; i<nums.size(); i++)
        {
            temp.clear();
            bt(temp,i,nums);
        }
        
        for(auto it : st)
            ans.push_back(it);
        
        return ans;   
    }
};