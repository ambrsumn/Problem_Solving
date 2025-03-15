class Solution {
public:

    bool isPossible(int mid, vector<int> &nums, int k)
    {
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] <= mid)
            {
                k--;
                i += 1;
            }
            
            if(k == 0)return true;
        }
        
        return false;
    }
    int minCapability(vector<int>& nums, int k) {

        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int ans = INT_MAX;
        int low = temp[0], high = temp.back();

        cout<<low<<" "<<high<<endl;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if(isPossible(mid, nums, k)) 
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
        
    }
};