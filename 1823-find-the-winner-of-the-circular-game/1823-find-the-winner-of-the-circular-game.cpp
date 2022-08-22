class Solution {
public:
    int findTheWinner(int n, int k) 
    {
        deque<int> dq;
        for(int i=1; i<=n; i++)
            dq.push_back(i);
        
    
    while(dq.size() != 1)
    {
        int count=1;
        while(count<k)
        {
            int d = dq.front();
            dq.pop_front();
            dq.push_back(d);
            
            count++;
        }
        // cout<<dq.front()<<endl;
        dq.pop_front();
    }
    
    return dq.front();
    }
};