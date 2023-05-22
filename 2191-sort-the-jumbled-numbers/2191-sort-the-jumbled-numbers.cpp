class Solution {
public:
    vector<int> sortJumbled(vector<int>& m, vector<int>& nums) 
    {
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        int count=0;
        for(int i=0; i<nums.size(); i++)
        {
            int n=0;
            int temp = nums[i];
            
            if(temp == 0)n = m[0];
            
            else
            {
                string str = to_string(temp);
                
                for(auto it : str)
                {
                    n = n*10 + m[int(it)-48];
                }
                
            }
            
            pq.push({n, count});
            
            count++;
        }
        // cout<<endl;
        
        vector<int> ans;
        
        while(!pq.empty())
        {
            pair<int,int> pr = pq.top();
            pq.pop();
            
            // cout<<pr.first<<" "<<pr.second<<endl;
            
            ans.push_back(nums[pr.second]);
        }
        
        return ans;
    }
};