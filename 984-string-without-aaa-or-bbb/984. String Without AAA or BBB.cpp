class Solution {
public:
    string strWithout3a3b(int a, int b) {

        int n = a+b;
        string ans = "";
        if(a == b) 
        {
            for(int i=0; i<n; i++)(i%2 == 0) ? ans += 'a' : ans += 'b';
            return ans;
        }

        else if(a > b)
        {
            while(b > a/2)
            {
                int count = 2;
                while(count-- && a>0)
                {
                    ans += 'a';
                    a--;
                }
                count=2;
                while(count-- && b>0)
                {
                    ans += 'b';
                    b--;
                }
            
            }
            while(b <= a/2)
            {
                int count = 2;
                while(count-- && a>0)
                {
                    ans += 'a';
                    a--;
                }
                if( b>0)
                {
                    ans += 'b';
                    b--;
                }
                if(b==0)break;
                
            }
        }

        else
        {
            while(a > b/2)
            {
                int count = 2;
                while(count-- && b>0)
                {
                    ans += 'b';
                    b--;
                }
                count=2;
                while(count-- && a>0)
                {
                    ans += 'a';
                    a--;
                }
            
            }
            while(a <= b/2)
            {
                int count = 2;
                while(count-- && b>0)
                {
                    ans += 'b';
                    b--;
                }
                if( a>0)
                {
                    ans += 'a';
                    a--;
                }
                if(a==0)break;
                
            }
        }

        while(a--)ans += 'a';
        while(b--)ans += 'b';

        return ans;
    }
};