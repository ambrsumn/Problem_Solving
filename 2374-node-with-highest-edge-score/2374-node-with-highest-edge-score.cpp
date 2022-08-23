class Solution {
public:
    int edgeScore(vector<int>& edges) 
    {
        unordered_map<long long, long long> mpp;
        
        for(long long i=0; i<edges.size(); i++)
        {
            mpp[edges[i]] += i;
        }
        
        int ans=-1;
        int curr = INT_MIN;
        
        for(auto it : mpp)
        {
            if(it.second>curr)
            {        
                ans = it.first;
                curr = it.second;
            }
            
            else if(it.second==curr && it.first<ans)
                ans=it.first;
        }
        
        return ans;
    }
};