//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int cap = 0;
    
    int recur(int i, vector<int> &p,bool bought, int count, vector<vector<vector<int>>> &dp)
    {
        if(i>=p.size())return 0;
        if(count>=cap)return 0;
        
        if(dp[i][bought][count] != -1)return dp[i][bought][count];
        
        int price=0;
        
        if(bought)
        {
            price = max(p[i] + recur(i+1,p,false,count+1, dp), recur(i+1,p,true,count, dp));
        }
        
        else
        {
            price = max(recur(i+1,p,true,count, dp)-p[i], recur(i+1,p,false,count, dp));
        }
        
        return dp[i][bought][count] = price;
    }
    
    int maxProfit(int K, int N, int A[]) 
    {
        vector<int> p;
        for(int i=0; i<N; i++)p.push_back(A[i]);
        
        cap = K;
        vector<vector<vector<int>>>dp(p.size(),vector<vector<int>>(2,vector<int>(K+1,-1)));
        return recur(0, p, false, 0, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends