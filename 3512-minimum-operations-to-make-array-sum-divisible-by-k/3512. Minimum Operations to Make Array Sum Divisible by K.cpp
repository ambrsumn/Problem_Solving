class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int totalSum = 0;

        for(auto it : nums)totalSum += it;

        if(totalSum%k == 0)return 0;
        return totalSum%k;
    }
};