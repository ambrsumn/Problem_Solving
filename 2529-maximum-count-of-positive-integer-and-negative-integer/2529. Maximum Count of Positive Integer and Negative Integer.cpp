class Solution {
public:
    int maximumCount(vector<int>& nums) 
    {
    int ncount=0;
    int pcount=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>0)
        pcount++;
        
        if(nums[i]<0)
        ncount++;
    }   
    int maxvalue=max(ncount,pcount);
    return maxvalue;
    }
};