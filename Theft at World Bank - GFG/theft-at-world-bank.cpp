// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> p)
	{
	    map<long double, long long, greater<long double> > mpp;
	    long double ans=0;
	    
	    for(int i=0; i<N; i++)
	    {
	        if(sqrt(w[i]) - int(sqrt(w[i])) != 0)
	        {
	            long double a = (long double)p[i]/(w[i]);
	            
	            mpp[a] = w[i];
	        }
	    }
	    
	       for(auto it : mpp)
	       {
	           if(it.second < C)
	           {
	               C -= it.second;
	               ans += (it.first * it.second);
	           }
	           
	           else
	           {
	               ans += (it.first * C);
	               C = 0;
	           }
	           
	           if(C == 0)
	           break;
	       }
	    
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		long long C;
		cin >> n >> C;
		vector<long long > w(n), p(n);
		for(int i = 0; i < n; i++){
		    cin >> w[i] >> p[i];
		}
		Solution ob;
		long double ans = ob.maximumProfit(n, C, w, p);
		cout << fixed << setprecision(3) << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends