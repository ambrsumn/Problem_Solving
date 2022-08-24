class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& arr) 
    {
        sort(arr.begin(), arr.end());
        priority_queue<int> pq;
        int curr = startFuel, i=0, ans=0;
        
        while(curr < target)
        {
            while(i<arr.size() && arr[i][0]<=curr)
            {
                pq.push(arr[i][1]);
                i++;
            }
            
            if(pq.empty())return -1;
            
            curr += pq.top();
            pq.pop();
            ans++;
        }
        
        return ans;
    }
};