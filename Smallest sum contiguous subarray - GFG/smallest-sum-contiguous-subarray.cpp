//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& a)
  {
      int ans = INT_MAX;
      int curr=0;
      int i=0;
      
      while(i<a.size())
      {
          curr += a[i];
          
          if(curr >= 0)
          {
              ans = min(curr, ans);
              curr = 0;
          }
          
          else
          {
              ans = min(ans, curr);
          }
          
          i++;
      }
      
      return ans;
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
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends