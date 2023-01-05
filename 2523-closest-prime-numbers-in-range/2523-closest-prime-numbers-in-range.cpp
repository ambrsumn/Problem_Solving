class Solution {
public:
    
void SieveOfEratosthenes(int n, vector<bool> &prime)
{
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
}
    
    vector<int> closestPrimes(int left, int n) 
    {
        vector<bool> prime(n+1, true);
        
        SieveOfEratosthenes(n, prime);
        
        vector<int> vec;
        
        for(int i=2; i<n+1; i++)
        {
            if(i >= left && i <= n && prime[i]==true)vec.push_back(i);
        }
        vector<int> ans;
        int temp = INT_MAX;
        
        if(vec.size() <= 1)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        
        for(int i=0; i<vec.size()-1; i++)
        {
            if(vec[i+1] - vec[i] < temp)
            {
                temp = min(temp, (vec[i+1]-vec[i]));
                ans.clear();
                
                ans.push_back(vec[i]);
                ans.push_back(vec[i+1]);
            }
            if(temp == 1)return ans;
        }
        
        return ans;
    }
};