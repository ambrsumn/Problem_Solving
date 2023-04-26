class Solution {
public:
    int addDigits(int num) 
    {
        long long temp = 0;
        
        do
        {
            temp=0;
            while(num != 0)
            {
                temp += num%10;
                num /= 10;
            }
            // cout<<temp<<endl;
            
            num = temp;
            
        }while(temp/10 != 0);
        
        return temp;
    }
};