class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {

        vector<int> ans;

        for(auto it : cost)ans.push_back(it);
        int mini = INT_MAX;

        for(int i=0; i<cost.size(); i++)
        {
            mini = min(mini, cost[i]);
            ans[i] = mini;
        }

        return ans;
        
    }
};