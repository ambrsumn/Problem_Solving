class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ans;
        int pos=0, neg=0;
        
        while(nums[pos]<0)
            pos++;
        while(nums[neg]>0)
            neg++;
        
        int count=0;
        while(pos<n && neg<n)
        {
            if(count%2 == 0)
            {
                ans.push_back(nums[pos]); pos++;
                while(pos<n &&nums[pos]<0)
                    pos++;
            }
            
            else
            {
                ans.push_back(nums[neg]); neg++;
                while(neg<n &&nums[neg]>0)
                    neg++;
            }
            count++;
        }
        ans.push_back(nums[neg]);
        
        return ans;
    }
};