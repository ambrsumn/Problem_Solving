class Solution {
public:
    int furthestBuilding(vector<int>& arr, int bricks, int ladders) 
    {
        priority_queue<int> pq;
        int i;
        
        for(i=0; i<arr.size(); i++)
        {
            if(i == arr.size()-1)
                break;
            
            if(arr[i+1] <= arr[i])
            {
                continue;
            }
            
            else
            {
                int d = arr[i+1] - arr[i];
                
                if(bricks >= d)
                {
                    bricks -= d;
                    pq.push(d);
                }
                
                else if(ladders > 0)
                {
                    if(pq.size())
                    {
                        int x = pq.top();
                        if(x > d)
                        {
                            bricks += x;
                            pq.pop();
                            pq.push(d);
                            bricks -= d;
                        }
                    }
                    
                    ladders--;
                }
                
                else
                    break;
            }
        }
        
        return i;
    }
};