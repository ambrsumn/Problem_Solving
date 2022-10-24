//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

    
    int recur(int i, int j, int k, string &s1, string &s2, string &s3, vector<vector<vector<int>>> &dp)
    {
        // cout<<i<<" "<<j<<" "<<k<<endl;
        
        if(i<0 || j<0 || k<0)return 0;
        
        if(dp[i][j][k] != -1)return dp[i][j][k];
        
        int ans = 0;
        
        if(s1[i] == s2[j] && s2[j] == s3[k])
        {
            ans = 1 + recur(i-1, j-1, k-1, s1, s2, s3, dp);
        }
        
        else
        {
            int o = recur(i-1,j,k,s1,s2,s3,dp);
            int t = recur(i,j-1,k,s1,s2,s3,dp);
            int th = recur(i,j,k-1,s1,s2,s3,dp);
            int f = recur(i-1,j-1,k,s1,s2,s3,dp);
            int fi = recur(i-1,j,k-1,s1,s2,s3,dp);
            int s = recur(i,j-1,k-1,s1,s2,s3,dp);
            
            ans = max({o,t,th,f,fi,s});
        }
        // return ans;
        return dp[i][j][k] = ans;
    }
    
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
vector<vector<vector<int>>> dp(n1, vector<vector<int>>(n2, vector<int>(n3, -1)));
        // memset(dp, -1, sizeof(dp));
        
        int ans = recur(n1-1, n2-1, n3-1, A, B, C, dp);
        return ans;
}