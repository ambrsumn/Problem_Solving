//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  long long dp[1001][1001];
  
  long long recur(int i, int sum, int coins[])
  {
      if(i==0)
      {
          if(sum%coins[0] == 0)return 1;
          return 0;
      }
      
      if(dp[i][sum] != -1)return dp[i][sum];
      
      if(sum<0)return 0;
      if(sum == 0)return 1;
      
      long long pick = recur(i, sum-coins[i], coins);
      long long np = recur(i-1, sum, coins);
      
      return dp[i][sum] = pick + np;
  }
  
    long long int count(int coins[], int N, int sum) 
    {
        memset(dp, -1, sizeof(dp));
        return recur(N-1, sum, coins);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends