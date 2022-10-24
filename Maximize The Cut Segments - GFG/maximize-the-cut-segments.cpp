//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{ public:
    
    int dp[10001];
    
    int recur(int n, int &x, int &y, int &z)
    {
        if(n == 0)return 0;
        if(n<0)return INT_MIN;
        
        if(dp[n] != -1)return dp[n];
        
        int f = recur(n-x, x, y, z);
        int s = recur(n-y, x, y, z);
        int t = recur(n-z, x, y, z);
        
        return dp[n] = (1 + max({f,s,t}));
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        memset(dp, -1, sizeof(dp));
        int ans = recur(n, x, y, z);
        return ans<0 ? 0 : ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends