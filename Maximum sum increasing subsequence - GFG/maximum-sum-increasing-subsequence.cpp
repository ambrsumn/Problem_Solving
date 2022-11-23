//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
	int dp[1001][1002];
	int recur(int i, int prev, int arr[], int n)
	{
	    if(i>=n)return 0;
	    
	    if(dp[i][prev+1] != -1)return dp[i][prev+1];
	    
	    int pick = 0, np = 0;
	    
	    if(prev == -1 || arr[prev] < arr[i])
	    pick = arr[i] + recur(i+1, i, arr, n);
	    
	    np = recur(i+1, prev, arr, n);
	    
	    return dp[i][prev+1] = max(pick, np);
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    memset(dp, -1, sizeof(dp));
	    return recur(0, -1, arr, n);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends