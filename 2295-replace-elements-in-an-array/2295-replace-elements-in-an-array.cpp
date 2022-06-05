class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& arr) 
    {
        unordered_map<int, int> mpp;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
            mpp[nums[i]] = i;
        
        for(int i=0; i<arr.size(); i++)
        {
            int x = mpp[arr[i][0]];
            
            mpp.erase(arr[i][0]);
            nums[x] = arr[i][1];
            mpp[arr[i][1]] = x;
        }
        
        
        return nums;
    }
};