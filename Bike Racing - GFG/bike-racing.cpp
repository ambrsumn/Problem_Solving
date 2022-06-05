// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isPossible(long long mid, long n, long M, long L, long h[], long a[])
    {
        long long total = 0;
        
        for(int i=0; i<n; i++)
        {
            long long curr = (h[i] + mid*a[i]);
            
            if(curr >= L)
            total += curr;
            
            if(total >= M)
            return true;
        }
        
        return false;
    }
    
    long buzzTime(long n, long M, long L, long H[], long A[])
    {
        long long ans = -1;
        long long low = 0, high = 1e10;
        
        while(low <= high)
        {
            long long mid = low + (high-low)/2;
            
            if(isPossible(mid, n, M, L, H, A))
            {
                high = mid-1;
                ans = mid;
            }
            
            else
            low = mid+1;
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends