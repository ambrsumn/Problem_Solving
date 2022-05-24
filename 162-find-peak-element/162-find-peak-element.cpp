class Solution {
public:
    int findPeakElement(vector<int>& arr) 
    {
        int low = 0, high = arr.size()-1;
        int n = high;
        int ans = -1;
        
        if(arr.size() == 1)
            return 0;
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            if(mid != 0 && mid != n)
            {
                if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
                {
                    return mid;
                }
                
                else if(arr[mid] < arr[mid-1])
                    high = mid-1;
                else
                    low = mid+1;
            }
            
            else if(mid == 0)
            {
                if(arr[mid] > arr[mid+1])
                    return mid;
                
                return mid+1;
            }
            
            else
            {
                if(arr[mid] > arr[mid-1])
                    return mid;
                
                return mid-1;
            }
        }
        
        return -1;
    }
};