class Solution {
public:
    int guessNumber(int n) 
    {
        int low =1,high=n;

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int ans=guess(mid);
            if(ans==0)
            {
            return mid;
            }
            else if(ans==-1)
            { 
            high=mid-1;
            }
            else
            {
            low=mid+1;
            }
        }
        return -1;
        
    }
};