class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int mini = INT_MAX;

        for(int i=0; i<cost.size(); i++)
        {
            mini = min(mini, cost[i]);
            cost[i] = mini;
        }

        return cost;
        
    }
};