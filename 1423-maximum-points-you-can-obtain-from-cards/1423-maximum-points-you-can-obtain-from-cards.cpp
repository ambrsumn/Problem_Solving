class Solution {
public:
    int maxScore(vector<int>& arr, int k) 
    {
        int n = arr.size();
        
        int i=0, sum=0, ans=INT_MIN;
        
        while(i<k)
        {
            sum += arr[i];
            i++;
        }
        i--;
        
        ans = max(ans, sum);
        
        int j = n-1;
        
        while(i >= 0)
        {
            sum -= arr[i];
            sum += arr[j];
            
            ans = max(ans, sum);
            i--;
            j--;
        }
        
        return ans;
    }
};