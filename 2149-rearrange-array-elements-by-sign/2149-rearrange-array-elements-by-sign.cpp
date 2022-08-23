class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        vector<int> ans;
        priority_queue<pair<int,int>> pos, neg;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]<0)
                neg.push({(i*-1),nums[i]});
            else
                pos.push({(i*-1),nums[i]});
        }
        
        int count=0;
        while(!pos.empty() && !neg.empty())
        {
            if(count%2 == 0)
            {
                ans.push_back(pos.top().second);
                pos.pop();
            }
            else
            {
                ans.push_back(neg.top().second);
                neg.pop();
            }
            count++;
        }
        ans.push_back(neg.top().second);
        neg.pop();
        
        return ans;
    }
};