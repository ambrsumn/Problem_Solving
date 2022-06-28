class Solution {
public:
    string smallestSubsequence(string s) 
    {
        map<char, int> mpp;
        
        for(auto it : s)
            mpp[it]++;
        
        stack<char> st;
        map<char, int> counter;
        
        for(int i=0; i<s.length(); i++)
        {
            // cout<<s[i]<<" "<<counter.count(s[i])<<" "<<mpp[s[i]]<<" ";
            
                if(!counter.count(s[i]))
                {
                    while(!st.empty() && st.top()>s[i] && mpp[st.top()]>0)
                    {
                        // mpp[st.top()]--;
                        
                        // if(counter.count(st.top()))
                            counter.erase(st.top());
                        
                        st.pop();
                    }
                }
            
            if(!counter.count(s[i]))
            {
                counter[s[i]] = 1;
                mpp[s[i]]--;
                st.push(s[i]);
            }
            else
                mpp[s[i]]--;
            
            // cout<<st.size()<<endl;
        
    }
        
        string ans = "";
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};