class Solution {
public:
    
set<int> st;  
vector<int> vec;
    
bool isPrime(int n)
{
    if (n <= 1)return false;
 
    for (int i = 2; i < n; i++)
        if (n % i == 0)return false;
 
    return true;
}
    
void recur(int n)
{
    int i=0;
    
    while(i<vec.size())
    {
        while(n%vec[i] == 0)
        {
            st.insert(i);
            n /= vec[i];
        }
        
        i++;
    }
}
    
    int distinctPrimeFactors(vector<int>& nums) 
    {
        for(int i=2; i<=1000; i++)if(isPrime(i))vec.push_back(i);
        
        for(auto it : nums)recur(it);
        
        return st.size();
    }
};