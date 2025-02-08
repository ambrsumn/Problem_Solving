class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int i=0, j=0, currSum=0, ans=INT_MAX;

        // cout<<i<<" "<<j<<" "<<currSum<<endl;

        while(i<nums.size())
        {
            // cout<<"YESS";
            if(currSum >= target)
            {
                cout<<"calculating "<<i<<" "<<j<<" "<<currSum<<endl;

                // let temp = i-1;
                // cout<<i<<endl;
                ans = min(ans, (i-j));

                currSum -= nums[j];
                j++;

                // cout<<"ans "<<i<<" "<<j<<" "<<currSum<<" "<<endl;
                cout<<"ans "<<ans<<" "<<currSum<<endl;
                if(ans == 1)return 1;
            }
            else 
            {
                // i++;
                currSum += nums[i];
                i++;

                cout<<"appending "<<i<<" "<<j<<" "<<currSum<<endl;
            }

            // cout<<"outside "<<i<<" "<<j<<" "<<currSum<<endl;
        }

        // if(i == nums.size)
        cout<<"out of loop"<<endl;
        cout<<i<<" "<<j<<" "<<currSum<<endl<<endl;
        while(currSum >= target && j <= i)
        {
        cout<<i<<" "<<j<<" "<<currSum<<endl;

            ans = min(ans, (i-j));
            currSum -= nums[j];
            j++;
        }
        // cout<<i<<" "<<j<<" "<<currSum<<endl;

        if(ans == INT_MAX && currSum < target)return 0;
        
        return ans;

        
    }
};