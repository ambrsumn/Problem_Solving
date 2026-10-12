class Solution {
public:
    int countPrimes(int n) 
    {
        vector<bool> vec(n, true);
        int count=0;
        
        for(int i=2; i<n; i++)
        {
            if(vec[i])
            {
                for(int j=2*i; j<n; j+=i)
                vec[j]=false;
            }
        }
        
        for(int i=2; i<n; i++)
        {
            if(vec[i])
                count++;
        }
        
        return count;
    }
};