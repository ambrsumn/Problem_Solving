class Solution {
public:
    int passThePillow(int n, int time) 
    {
        int temp = 1, curr = 0;
        bool add=true;
        
        while(curr < time)
        {
            // cout<<temp<<" "<<curr<<endl;
            
            if(add)temp++;
            else temp--;
            curr++;
            
            if(curr%(n-1) == 0)add = !add;
        }
        
        return temp;
    }
};