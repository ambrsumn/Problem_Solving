class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        priority_queue<int> pq;
        int count=1;
        
        for(auto it : arr)
        {
            if(k == 0)return pq.top();
            
            while(k != 0 && count < it)
            {
                pq.push(count);
                k--;
                count++;
            }
            
            count=it+1;
        }
        while(k != 0)
        {
                pq.push(count);
                k--;
                count++;
        }
        
        return pq.top();
    }
};