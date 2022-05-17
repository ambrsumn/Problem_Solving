class Solution {
public:
    int findMin(vector<int>& arr) 
    {
        
        int n = arr.size();
        
    int key = arr[0];
    int ans=-1;

    int low=0, high=(n-1);

    while(low <= high)
    {
        int mid = low + (high-low)/2;

        if(arr[mid] >= key)
        {
            key = arr[mid];
            low = mid+1;
        }

        else
        {
            key = arr[mid];
            ans = mid;
            high = mid-1;
        }
    }

    if(ans == -1)
    ans = 0;

    return arr[ans];        
    }
};