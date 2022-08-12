class Solution {
public:
    int reverse(int x) 
    {
        long long num=0;
        
        while(x != 0)
        {
            // if(num>0 || (x%10)>0)
            num = (num*10)+(x%10);
            
            if(num > INT_MAX || num < INT_MIN)
                return 0;
            
            x /= 10;
        }
        
        // cout<<flag<<endl;
//         cout<<num<<endl;
        
        return num;
    }
};