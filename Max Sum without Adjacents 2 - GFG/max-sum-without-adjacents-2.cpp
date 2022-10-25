//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  
  int dp[1000001];
  
  int recur(int i, vector<int> &a)
  {
      if(i >= a.size())return 0;
      
      if(dp[i] != -1)return dp[i];
      
      int pick=0, np=0, po=0;
      
      pick = a[i] + recur(i+3, a);
      if(i+1 < a.size())pick += a[i+1];
      
      po = a[i] + recur(i+2, a);
      
      np = recur(i+1, a);
      
      return dp[i] = max({pick, np, po});
  }
  
  int findMaxSum(vector<int>& a)
  {
      memset(dp, -1, sizeof(dp));
      return recur(0, a);
  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends