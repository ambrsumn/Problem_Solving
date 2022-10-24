//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int mod = (int)(1e9+7);
    long long dp[5001][101];
    
    long long recur(int i, int k, int cont)
    {
        if(i == 0)
        {
            if(cont == 2)return k-1;
            
            else return k;
        }
        
        if(dp[i][cont] != -1)return dp[i][cont];
        
        long long ans = 0;
        
        if(cont == 0) ans = (k*recur(i-1, k, 1))%mod;
        
        else if(cont == 1) ans = ((k-1)*recur(i-1, k, 1) + recur(i-1, k, 2))%mod;
        
        else if(cont == 2) ans = ((k-1)*recur(i-1, k, 1))%mod;
        
        dp[i][cont] = ans;
    }
    
    long long countWays(int n, int k)
    {
        memset(dp, -1, sizeof(dp));
        return recur(n-1, k, 0);
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends