class Solution {
public:

    int maxSum(vector<int>& nums, int i)
    {
        int sum=0, lsum=0, rsum=0, maxi=INT_MIN;
        int n = nums.size();
        // cout<<i<<" "<<lsum<<" "<<rsum<<endl;

        int j = (i+1)%n;

        //right sum - max possible
        while(j != i)
        {
            // cout<<"r "<<j<<endl;
            // cout<<i<<" "<<j<<endl;
            // cout<<i<<" "<<j<<" ";
            sum += nums[j];
            rsum = max(rsum, sum);
            
            if(sum <= 0)break;

            (j+1 >= n) ? j = (j+1)%n : j++; 
            // cout<
        }
        sum=0;


        if(j == i)
        {
            // cout<<i<<" "<<rsum<<" \n\n";
            return max(nums[i] + lsum + rsum, lsum+rsum);
        }


        //left sum - max possible
        j = (i-1+n)%n;
        while(j != i)
        {
            // cout<<"l "<<j<<endl;
            sum += nums[j];
            lsum = max(lsum, sum);
            
            if(sum <= 0)break;
            
            (j-1 < 0) ? j = (j-1+n)%n : j--; 
            // j = (j-1+n)%n;
        }

        // cout<<i<<" "<<lsum<<" "<<rsum<<endl<<endl;;

        return max({nums[i] + lsum + rsum, lsum, rsum, nums[i]});
    }

    int maxSubarraySumCircular(vector<int>& nums) {

        int maxi = INT_MIN;
        for(auto it : nums)maxi = max(maxi, it);
        if(maxi < 0)return maxi;

        int ans = INT_MIN;

        for(int i=0; i<nums.size(); i++)ans = max(ans, maxSum(nums, i));

        return ans;
        
    }
};