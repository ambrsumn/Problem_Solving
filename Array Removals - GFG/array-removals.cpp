//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
 int removals(vector<int>& arr, int k){

        int mini = INT_MAX,n=arr.size();

        sort(arr.begin(),arr.end());

        for(int j=n-1; j>=0; j--){

            int i = upper_bound(arr.begin(),arr.end(),arr[j]-k)-arr.begin();

            mini = min(mini, n-(j-i+1)) ;

        }

        return mini;

    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends