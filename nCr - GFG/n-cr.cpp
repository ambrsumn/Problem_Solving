//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

int mod = (int)(1e9+7);
int dp[1001][801];

int recur(int n, int r)
{
    if(n == r || r == 0)return 1;
    if(r == 1 || n-r == 1)return n;
    
    if(dp[n][r] != -1)return dp[n][r];
    
    return dp[n][r] = ((recur(n-1, r-1) + recur(n-1, r)))%mod;
}

    int nCr(int n, int r)
    {
        memset(dp, -1, sizeof(dp));
        
        if(r>n)return 0;
        r = min(r, n-r);
        
        return recur(n, r);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends