class Solution {
public:
    bool isNondecreasing(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        while (!isNondecreasing(nums)) {
            int min_sum = INT_MAX;
            int index = -1;
            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < min_sum) {
                    min_sum = sum;
                    index = i;
                }
            }
            vector<int>temp;
            for(int i = 0;i<nums.size();i++){
                if(i==index){
                    temp.push_back(nums[i]+nums[i+1]);
                    i++;
                }else{
                    temp.push_back(nums[i]);
                }
            }
            nums = temp;
            ++ops;
        }
        return ops;
    }
};