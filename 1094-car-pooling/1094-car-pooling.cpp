class Solution {
public:
    
static bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[1] < v2[1];
}
    
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        sort(trips.begin(), trips.end(), sortcol);
        
       priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // for(int i=0; i<trips.size(); i++)
        // {
        //     for(int j=0; j<trips[i].size(); j++)
        //     {
        //         cout<<trips[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for(int i=0; i<trips.size(); i++)
        {
            while(!pq.empty() && trips[i][1] >= pq.top().first)
            {
                capacity += pq.top().second;
                pq.pop();
            }
            
            if(trips[i][0] <= capacity)
            {
                capacity -= trips[i][0];
                pair<int,int> pr;
                pr.first = trips[i][2];
                pr.second = trips[i][0];
                
                pq.push(pr);
            }
            
            else
            {
                return false;
            }
        }
        
        return true;
    }
};