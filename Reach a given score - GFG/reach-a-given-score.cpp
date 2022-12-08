//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends
// Complete this function

int dp[1001][4];

long long int recur(int n, int i, vector<int> &vec)
{
    if(n == 0)return 1;
    if(n < 0)return 0;
    
    if(i>=vec.size())return 0;
    
    if(dp[n][i] != -1)return dp[n][i];
    int take=0, nt=0;
    
    take = recur(n-vec[i], i, vec);
    nt = recur(n, i+1, vec);
    
    return dp[n][i] = take+nt;
    
}

long long int count(long long int n)
{
    memset(dp, -1, sizeof(dp));
    vector<int> vec = {3,5,10};
	return recur(n, 0, vec);
}

//{ Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends