// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n)
    {
        map<int, int> mpp;
        vector<int> ans;
        
        for(int i=0; i<n; i++)
        {
            mpp[arr[i]]++;
        }
        
        multimap<int, int> fmpp;
        
        for(auto it : mpp)
        {
            int a = it.first;
            int b = it.second*(-1);
            
            fmpp.insert(pair<int, int>(b, a));
        }
        
        for(auto it : fmpp)
        {
            int c = it.first*(-1);
            
            while(c > 0)
            {
                ans.push_back(it.second);
                c--;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}

  // } Driver Code Ends