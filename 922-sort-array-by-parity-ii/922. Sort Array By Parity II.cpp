class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int>ans(nums.size());
        int even=0;
        int odd=1;
        for(auto it:nums){
            if(it%2==0){
                ans[even]=it;
                even+=2;
            }else{
                ans[odd]=it;
                odd+=2;
            }
        }
        return ans;
    }
};
