class Solution {
public:
    int majorityElement(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        
        long long count=0;
        int n = arr.size();
        int d = n/2;
        
        for(int i=0; i<n; i++)
        {
            if(i == 0)
                count=1;
            
            else if(i > 0 && arr[i] == arr[i-1])
                count++;
            
            else
                count=1;
            
            if(count > d)
            {
                return arr[i];
            }
                
        }
        
        return 0;        
    }
};