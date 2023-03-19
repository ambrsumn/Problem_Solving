class Solution {
public:
    long long findScore(vector<int>& nums) 
    {
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        
        for(long long i=0; i<nums.size(); i++)pq.push({nums[i], i});
        
        vector<long long> count(nums.size(), -1);
        long long ans=0;
        
        while(!pq.empty())
        {
            pair<int,int> pr = pq.top();
            pq.pop();
            
            if(count[pr.second] == 1)continue;
            else
            {
                count[pr.second] == 1;
                ans += pr.first;
                
                if(pr.second-1 >= 0)count[pr.second-1]=1;
                if(pr.second+1 < nums.size())count[pr.second+1]=1;
            }
        }
        
        return ans;
    }
};