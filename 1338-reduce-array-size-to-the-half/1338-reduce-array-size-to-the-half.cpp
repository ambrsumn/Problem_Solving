class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        unordered_map<int,int> mpp;
        for(auto it : arr)
            mpp[it]++;
        priority_queue<pair<int,int>> pq;
        
        for(auto it : mpp)
            pq.push({it.second, it.first});
        
        int n = arr.size();
        int p = n/2, ans=0;
        
        while (!pq.empty() && n>p)
        {
            ans++;
            n -= pq.top().first;
            pq.pop();
        }
        
        return ans;
    }
};