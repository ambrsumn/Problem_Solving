class Solution {
public:
    bool sumOfNumberAndReverse(int num) 
    {
        for(int i=0; i<=num; i++)
        {
            string one = to_string(i);
            string rev = one;
            reverse(rev.begin(), rev.end());
            
            int sum = stoi(one)+stoi(rev);
            
            // cout<<sum<<endl;
            
            if(sum == num)return true;
        }
        
        return false;
    }
};