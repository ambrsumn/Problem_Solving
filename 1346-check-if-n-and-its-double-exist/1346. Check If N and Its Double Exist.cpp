class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        int n=arr.size();
            

        for (int i=0;i<n;i++) 
        {
            int low=0,high=n-1;
            int target=2*arr[i];
            while (low<=high)
            {
                int mid=low+(high-low)/2;
                if (mid!=i && arr[mid]==target)
                {
                    return true;
                }
                else if 
                (arr[mid]<target)
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
        }
        return false;
    }
};