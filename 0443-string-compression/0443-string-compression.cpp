class Solution {
public:
    int compress(vector<char>& chars) 
    {
        string temp="";
        char curr = chars[0];
        int len=0;
        
        for(auto it : chars)
        {
            if(it == curr)
                len++;
            
            else
            {
                temp.push_back(curr);
                if(len != 1)
                temp += to_string(len);
                
                len=1;
                curr = it;
            }
        }
        temp.push_back(curr);
        if(len != 1)
        temp += to_string(len);
        
        chars.clear();
        
        for(auto it : temp)
            chars.push_back(it);
        
        return temp.length();
    }
};