class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> vec;
        sort(nums.begin(), nums.end());
        set<vector<int>> st;

        for(int i=0; i<nums.size()-2; i++)
        {
            int j=i+1, k=nums.size()-1;
            int fixed = nums[i];
            // cout<<nums[i]<<endl<<endl;

            while(j<k)
            {
                int total = fixed+nums[j]+nums[k];
                // cout<<nums[j]<<" "<<nums[k]<<" "<<total<<endl;  
                if(total == 0)
                {
                    // vector<int> temp = {nums[i], nums[j], nums[k]};
                    // sort(temp.begin(), temp.end()); 
                    st.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(total < 0)j++;
                else k--;
            }
        }

        for(auto it : st)
        {
            vec.push_back(it)
;        }

        return vec;
        
    }
};