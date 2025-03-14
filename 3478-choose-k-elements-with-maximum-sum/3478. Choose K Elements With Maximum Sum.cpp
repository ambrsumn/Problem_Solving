class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {

        int n = nums1.size();
        vector<long long> ans(n, 0);
        vector<pair<int,int>> vec;

        for(int i=0; i<n; i++)vec.push_back({nums1[i], i});
        sort(vec.begin(), vec.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> left;
        long long currentSum = 0;

        for(int i=0; i<n; i++)
        {
            if(i != 0)
            {
                if(vec[i-1].first != vec[i].first) 
                {
                    for(auto it : left)
                    {
                        pq.push(nums2[it]);
                        currentSum += nums2[it];

                        if(pq.size() > k)
                        {
                            currentSum -= pq.top();
                            pq.pop();
                        }
                    }
                    left.clear();
                    
                    pq.push(nums2[vec[i-1].second]);
                    
                    currentSum += nums2[vec[i-1].second];

                    if(pq.size() > k)
                    {
                        currentSum -= pq.top();
                        pq.pop();
                    }

                }
                else left.push_back(vec[i-1].second);


            }

            long long indexSum = 0;

            ans[vec[i].second] = currentSum;

        }

        return ans;
    }
};