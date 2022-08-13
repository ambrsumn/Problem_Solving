class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> mpp;
        vector<int> ans;
        
        for(auto it : nums)
        {
            mpp[it]++;
        }
        
        priority_queue<pair<int,int>> pq;
        
        for(auto it : mpp)
        {
            pq.push({it.second, it.first});
        }
        
        while(!pq.empty() && k--)
        {
            pair<int,int> pr = pq.top();
            pq.pop();
            ans.push_back(pr.second);
        }
        
        return ans;
        
    }
};