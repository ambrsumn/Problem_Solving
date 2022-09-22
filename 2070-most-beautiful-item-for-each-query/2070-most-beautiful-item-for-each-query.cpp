class Solution {
public:
    
   void print2(priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> gq)
    {
        while(!gq.empty())
        {
            cout<<gq.top().first<<" "<<gq.top().second<<endl;
            gq.pop();
        }
        return;
    }
    
    vector<int> maximumBeauty(vector<vector<int>>& it, vector<int>& q) 
    {
        vector<int> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> gq;
        unordered_map<int,int> mpp;
        
        vector<int> temp = q;
        sort(q.begin(), q.end());
        
        for(int i=0; i<it.size(); i++)
            gq.push({it[i][0],it[i][1]});
        
        int maxi = 0;
        
        // print2(gq);
        
        for(auto it : q)
        {
            int curr=0;
            // cout<<it<<" : ";
            
            while(!gq.empty() && it >= gq.top().first)
            {
                curr = max(curr, gq.top().second);
                gq.pop();
            }
            
            // cout<<curr<<" "<<maxi<<" "<<gq.size()<<endl;
            maxi = max(maxi, curr);
            mpp[it]=maxi;
        }
        
        for(auto it : temp)
            ans.push_back(mpp[it]);
        
        return ans;
    }
};