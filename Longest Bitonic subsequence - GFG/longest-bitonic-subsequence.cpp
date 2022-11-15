//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    vector<int> dp1(nums.size(), -1);
	    vector<int> dp2(nums.size(), -1);
	    vector<int> temp;
	    temp.push_back(nums[0]);
	    dp1[0] = 1;
	    
	    for(int it=1; it<nums.size(); it++)
	    {
	        
            int i = lower_bound(temp.begin(), temp.end(), nums[it])-temp.begin();

	        if(nums[it] > temp.back())temp.push_back(nums[it]);
	        
	        else temp[i] = nums[it];
	        
	        dp1[it] = temp.size();
	    }
	    
	    reverse(nums.begin(), nums.end());
	    temp.clear();
	    
	    temp.push_back(nums[0]);
	    dp2[0] = 1;
	    
	    for(int it=1; it<nums.size(); it++)
	    {
	        
            int i = lower_bound(temp.begin(), temp.end(), nums[it])-temp.begin();

	        if(nums[it] > temp.back())temp.push_back(nums[it]);
	        
	        else temp[i] = nums[it];
	        
	        dp2[it] = temp.size();
	    }
	    
	    int ans = -1;
	    
	    reverse(dp2.begin(), dp2.end());
	    
	    for(int i=0; i<dp1.size(); i++)
	    {
	        ans = max(ans, dp1[i]+dp2[i]-1);
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends