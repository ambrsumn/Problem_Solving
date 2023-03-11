class Solution {
public:
    
    int t = 0;
    int mod = (int)(1e9+7);
    int dp[51][51][1001];
    
    int recur(int i, int curr, vector<vector<int>> &vec)
    {
        if(curr == t)return 1;
        if(i >= vec.size())return 0;
        if(curr > t)return 0;
        
        if(vec[i][0] < 0)return 0;
        
        if(dp[i][vec[i][0]][curr] != -1)return dp[i][vec[i][0]][curr]; 
            
        int pick = 0, np=0;
        
        if(vec[i][0] > 0)
        {
            vec[i][0]--;
            pick = recur(i, curr+vec[i][1], vec); 
            vec[i][0]++;
        }
        
        np = recur(i+1, curr, vec);
        
        return dp[i][vec[i][0]][curr] = (pick+np)%mod;
    }
    
    int waysToReachTarget(int target, vector<vector<int>>& types) 
    {
        memset(dp, -1, sizeof dp);
        t = target;    
        return recur(0, 0, types);
    }
};