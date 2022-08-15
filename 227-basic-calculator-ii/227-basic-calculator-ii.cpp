class Solution {
public:
    
    int num(int &i, string &s)
    {
        long long num=0;
        
        while(i<s.length() && s[i]>=48 && s[i]<=57)
        {
            num = num*10 + s[i]-'0'; i++;
        }
        
        i--;
        return num;
    }
    
    int calculate(string s) 
    {
        int ans=0;
        stack<int> st;
        int sign=1;
        
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]>=48 && s[i]<=57)
            {
                int no = num(i,s);
                st.push(no*sign);
                sign=1;
            }
            
            else if(s[i] == '-')
                sign=-1;
            
            else if(s[i] == '/')
            {
                int d = st.top();
                st.pop();
                i++;
                int no2 = num(i,s);
                
                st.push(d/no2);
            }
            
            else if(s[i] == '*')
            {
                int d = st.top();
                st.pop();
                i++;
                int no2 = num(i,s);
                
                st.push(d*no2);
            }
            
        }
        
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        
        return ans;
        
    }
};