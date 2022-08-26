class Solution {
public:
    
    bool reorderedPowerOf2(int n) 
    {
        string s=to_string(n);
        sort(s.begin(),s.end());
        for(int i=0;i<=30;i++){
            string temp="";
            int t=pow(2,i);
            temp=to_string(t);
            sort(temp.begin(),temp.end());
            if(temp==s)
                return true;
            
        }
        return false;
    }
};