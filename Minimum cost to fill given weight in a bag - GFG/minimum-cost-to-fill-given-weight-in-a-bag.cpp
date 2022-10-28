//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
	public:
	
	int dp[201][201];
	int recur(int i, int cost[], int w, int &n)
	{
	    if(w<0)return 1e8;
	    if(w == 0)return 0;
	    
	    if(i>=n)return 1e8;
	    
	    if(dp[i][w] != -1)return dp[i][w];
	    
	    int pick=INT_MAX, np=INT_MAX;
	    
	    if(cost[i] != -1)
	    pick = cost[i] + recur(i, cost, w-(i+1), n);
	    
	    np = recur(i+1, cost, w, n);
	    
	   // cout<<pick<<" "<<np<<endl;
	    return dp[i][w] = min(pick, np);
	}
	
	int minimumCost(int cost[], int N, int W) 
	{ 
	    memset(dp, -1, sizeof(dp));
        return recur(0, cost, W, N);
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends