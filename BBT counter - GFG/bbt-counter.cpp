//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
  int mod = (int)(1e9+7);
  int dp[1001];
  
  long long recur(int h)
  {
      if(h <= 1)return 1;
      
      if(dp[h] != -1)return dp[h];
      
      return dp[h] = (recur(h-1)*(recur(h-1) + recur(h-2)*2))%mod;
  }
  
    long long int countBT(int h) 
    { 
        memset(dp, -1, sizeof(dp));
        return recur(h);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}

// } Driver Code Ends