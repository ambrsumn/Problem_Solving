class Solution {
public:
    int maximumSum(vector<int>& nums) 
    {
        map<int, priority_queue<int>> cnt;
        
        for(auto it : nums)
        {
            int rough = it;
            int temp = 0;
            
            while(it != 0)
            {
                temp += it%10;
                it /= 10;
            }
            
            cnt[temp].push(rough);
        }
        
        int ans = INT_MIN;
        
        for(auto it : cnt)
        {
            if(it.second.size() >= 2)
            {
                int temp = it.second.top();
                it.second.pop();
                temp += it.second.top();
                
                ans = max(ans, temp);
            }
        }
        
        return ans>INT_MIN ? ans : -1;
    }
};