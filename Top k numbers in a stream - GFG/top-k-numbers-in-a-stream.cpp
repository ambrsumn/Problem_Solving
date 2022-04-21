// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> kTop(int a[], int n, int k) 
    { 
        unordered_map<int, int> mpp;
        
        vector<int> ans;
        
        for(int i=0; i<n; i++)
        {
            priority_queue<pair<int, int> > pq;
            mpp[a[i]]++;
            
            for(auto it : mpp)
            {
                pair<int, int> pp;
                pp.first = it.second;
                pp.second = it.first*(-1);
                
                pq.push(pp);
            }
            
            int count=k;
            
            while((count > 0) && !pq.empty())
            {
                pair<int, int> ansr = pq.top();
                pq.pop();
                
                ans.push_back(-1*ansr.second);
                count--;
            }
        }
        
        return ans;
    }
};


// { Driver Code Starts.

int main() {
	long long t;
	
	cin >> t;
	
	while(t--){
	    long long n;
	    long long k;
	    cin >> n;
	    cin >> k;
	    int a[n];
	    for(long long i = 0;i<n;i++){
	        cin >> a[i];
	    }
	        Solution ob;
	        vector<int> ans;
	        ans=ob.kTop(a,n,k);
	        for(int i=0;i<ans.size();i++)
	        {
	        cout<<ans[i];
	        cout<<" ";
	        }
	        cout<<'\n';
	    }
	return 0;
}
  // } Driver Code Ends