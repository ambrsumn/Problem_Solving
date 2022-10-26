class Solution {
public:
    
    int dp[100001];
int lower_bound(vector<array<int,3>> &arr, int N, int X)
{
    int mid;
    int low = 0;
    int high = N;
 
    while (low < high) {
        mid = low + (high - low) / 2;
 
        if (X <= arr[mid][0]) {
            high = mid;
        }
 
        else {
            low = mid + 1;
        }
    }
    if(low < N && arr[low][0] < X) {
       low++;
    }
    return low;
}
    
    int recur(int i, vector<array<int,3>> &s)
    {
        if(i>=s.size())return 0;
        
        if(dp[i] != -1)return dp[i];
        
        int pick=0, np=0;
        
        int next = lower_bound(s, s.size(), s[i][1]);
        
        pick = s[i][2] + recur(next, s);
        
        np = recur(i+1, s);
        
        return dp[i] = max(pick, np);
    }
    
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) 
    {
        vector<array<int,3>> arr;
        int n = s.size();
        
        for(int i=0;i<n;i++)
        {
            arr.push_back({s[i],e[i],p[i]});
        }
        
        sort(arr.begin(),arr.end());
        
        memset(dp, -1, sizeof(dp));
        return recur(0, arr);
    }
};