class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int> pq;

        for(auto it : nums)
        {
            pq.push(it);
        }
        int ans = INT_MIN;

        while(!pq.empty())
        {
            if(k == 1)
            {
                ans = pq.top();
                break;
            }
            else
            {
                pq.pop();
                k--;
            }
        }

        return ans;
    }
};