class Solution {
public:
    
  vector<int> maximumBeauty(vector<vector<int>>& it, vector<int>& q) 
    {
        vector<int> ans, temp = q;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> gq;
        unordered_map<int,int> mpp;
        
        sort(q.begin(), q.end());
        
        for(int i=0; i<it.size(); i++)
            gq.push({it[i][0],it[i][1]});
        
        int maxi = 0;
        
        for(auto it : q)
        {
            int curr=0;
            while(!gq.empty() && it >= gq.top().first)
            {
                curr = max(curr, gq.top().second);
                gq.pop();
            }
            maxi = max(maxi, curr);
            mpp[it]=maxi;
        }
        
        for(auto it : temp)
            ans.push_back(mpp[it]);
        
        return ans;
    }
};