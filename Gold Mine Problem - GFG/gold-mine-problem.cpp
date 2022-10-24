//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

int col=0, row=0;
int dp[51][51];

int recur(int i, int j, vector<vector<int>> &gold)
{
    
    if(i<0 || i>=row)return INT_MIN;
    if(j == col-1) return gold[i][j];
    
    if(dp[i][j] != -1)return dp[i][j];
    
    int upr = recur(i-1, j+1, gold);
    int downr = recur(i+1, j+1, gold);
    int right = recur(i, j+1, gold);
    
    
    return dp[i][j] = (gold[i][j] + max({upr, downr, right}));
}

    int maxGold(int n, int m, vector<vector<int>> gold)
    {
        memset(dp, -1, sizeof(dp));
        
       col=m;
       row=n;
       int ans = INT_MIN;
       
      for(int i=0; i<row; i++) ans = max(ans, recur(i, 0, gold));
       
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends