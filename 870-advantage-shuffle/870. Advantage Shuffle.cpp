class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(), nums1.end(), greater<int>());
        vector<int> ans(nums1.size(), -1);
        multimap<int, int> mpp;
        vector<int> temp;

        for(int i=0; i<nums2.size(); i++)mpp.insert(make_pair(nums2[i], i));

        for(auto it : mpp)
        {
            int num = it.first;
            if(nums1.size() == 0)break;

            while(nums1.size()>0 && nums1.back() <= num)
            {
                temp.push_back(nums1.back());
                nums1.pop_back();
            }

            if(nums1.size() > 0)
            {
                ans[it.second] = nums1.back();
                nums1.pop_back();
            }
        }

        for(int i=0; i<ans.size(); i++)
        {
            if(ans[i] == -1)
            {
                ans[i] = temp.back();
                temp.pop_back();
            }
        }

        return ans;        
    }
};