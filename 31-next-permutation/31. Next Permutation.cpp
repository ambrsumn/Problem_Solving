class Solution {
public:
    void nextPermutation(vector<int>& nums) {

    int n = nums.size();
    for(int i=n-1; i>=0; i--)
    {
        for(int j=n-1; j>i; j--)
        {

            if(nums[i] < nums[j])
            {
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;

                sort(nums.begin()+i+1, nums.end());
                return;
            }
        }
    }

    sort(nums.begin(), nums.end());
    return;
        
    }
};