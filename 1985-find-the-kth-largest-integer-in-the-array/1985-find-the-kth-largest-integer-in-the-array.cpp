class Solution {
public:
    
    static bool cmp(const string &a, const string &b)
    {
        if(a.size() == b.size())
        {
            for(int i=0; i<a.length(); i++)
            {
                if(a[i] != b[i])
                return a[i] > b[i];
            }
        }
        
        return a.size() > b.size();
        
        // return true;
    }
    
    string kthLargestNumber(vector<string>& nums, int k) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end(), cmp);
        reverse(nums.begin(), nums.end());
        
        // for(auto it : nums)
        //     cout<<it<<" ";
        // cout<<endl;
        
        return nums[n-k];
    }
};