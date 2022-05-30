class Solution {
public:
    string reverseWords(string s) 
    {
        int prev=-1, next=-1, flag=0;
        string mod;
        
        for(int i=0; i<s.length(); i++)
        {
            if(flag == 0 and s[i] != ' ')
            {
                prev = i;
                flag = 1;
            }
            
            if(prev != -1 && (s[i] == ' ' || i == (s.length()-1)))
            {
                if(s[i] == ' ')
                next = i-1;
                else
                next = i;
            }
            
            if(prev != -1 and next != -1)
            {
                // cout<<prev<<" "<<next<<endl;
                
                while(prev <= next)
                {
                    mod += s[prev];
                    prev++;
                }
                mod += ' ';
                prev = -1;
                next = -1;
                flag = 0;
            }
            
        }
        
        if(mod.back() == ' ')
        mod.pop_back();
        
        cout<<mod<<endl;
        
        reverse(mod.begin(), mod.end());
        
        flag = 0;
        prev=-1; next=-1;
        
        // cout<<s<<endl;
        
        for(int i=0; i<mod.length(); i++)
        {
            if(flag == 0 and mod[i] != ' ')
            {
                prev = i;
                flag = 1;
            }
            
            else if(mod[i] == ' ' || i == (mod.length()-1))
            {
                if(mod[i] == ' ')
                next = i-1;
                else
                next = i;
            }
            
            if(prev != -1 and next != -1)
            {
                // cout<<prev<<" "<<next<<endl;
                
                while(prev < next)
                {
                    swap(mod[prev], mod[next]);
                    prev++;
                    next--;
                }
                
                prev = -1;
                next = -1;
                flag = 0;
            }
            
        }
        
        return mod;
        
    }

};