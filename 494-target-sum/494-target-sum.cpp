class Solution {
public:
    
    int recur(int i, int k, vector<int> &arr)
    {
        if(i<0)
        {
            if(k==0)return 1;
            return 0;
        }
        
        return recur(i-1,k-arr[i],arr) + recur(i-1,k+arr[i],arr);
    }
    
    int findTargetSumWays(vector<int>& arr, int k) 
    {
        int n = arr.size();
        
        return recur(n-1,k,arr);
    }
};