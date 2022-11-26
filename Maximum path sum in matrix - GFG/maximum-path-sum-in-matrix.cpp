//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int n=0, m=0;
    int dp[501][501];
    
    int recur(int i, int j, vector<vector<int>> &ma)
    {
        if(i >= n)return 0;
        if(j>=m || j<0)return INT_MIN;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        int d = ma[i][j] + recur(i+1, j, ma);
        int dr = ma[i][j] + recur(i+1, j+1, ma);
        int dl = ma[i][j] + recur(i+1, j-1, ma);
        
        return dp[i][j] = max({d,dr,dl});
    }
    
    int maximumPath(int N, vector<vector<int>> ma)
    {
        n = ma.size();
        m = ma[0].size();
        memset(dp, -1, sizeof(dp));
        
        int ans = INT_MIN;
        
        for(int i=0; i<m; i++)ans = max(ans, recur(0, i, ma));
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends