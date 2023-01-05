class Solution {
public:
    int countDigits(int num) 
    {
        int temp = num;
        int ans = 0;
        while(num != 0)
        {
            int dig = num%10;
            if(temp%dig == 0)ans++;
            num /= 10;
        }
        
        return ans;
    }
};