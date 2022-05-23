class Solution {
public:
    
int waysToSplitArray(vector<int> & nums) 
{
    
long long prefix=0;
int c=0;long long left=0;
    
for(int i=0;i<nums.size();i++)
{
prefix+=nums[i];
}
    
for(int i=0;i<nums.size()-1;i++)
{
left += nums[i];
    
prefix -= nums[i];
    
if(prefix<=left)
{
c++;
}

    }
    return c;
    
}
};