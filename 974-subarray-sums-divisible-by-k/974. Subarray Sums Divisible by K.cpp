class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int K) 
    {
        int n = arr.size();
	    int curr = 0, ans = 0;
	    map<int,int> mpp;
	    mpp[0]=1;
	    
	    for(int i=0; i<n; i++)
	    {
	        curr += arr[i];
	        int left = curr%K;
	        
	        if(left<0)left += K;
	        
	        if(mpp[left])ans += mpp[left];
	        
	        else
	        mpp.erase(left);
	        
	        mpp[left]++;
	    }
	    
	    return ans;
    }
};